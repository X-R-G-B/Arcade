/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AutoTurnSystem
*/

#include <map>
#include <string>
#include <vector>
#include "ArcadeStruct.hpp"
#include "Sprite.hpp"
#include "Direction.hpp"
#include "Forward.hpp"
#include "MagicValue.hpp"
#include "ChangeDir.hpp"
#include "NibblerCompType.hpp"
#include "NibblerWallComponent.hpp"
#include "AutoTurnSystem.hpp"

Arcade::Vector2f Nibbler::System::AutoTurnSystem::toNextCase(const Arcade::Vector2f &pos, const Nibbler::Direction &direction)
{

    if (direction == Direction::UP) {
        return {pos.x, pos.y - TO_FLOAT(PARCELL_SIZE)};
    } else if (direction == Direction::DOWN) {
        return {pos.x, pos.y + TO_FLOAT(PARCELL_SIZE)};
    } else if (direction == Direction::LEFT) {
        return {pos.x - TO_FLOAT(PARCELL_SIZE), pos.y};
    } else if (direction == Direction::RIGHT) {
        return {pos.x + TO_FLOAT(PARCELL_SIZE), pos.y};
    }
    return {pos.x, pos.y};
}

bool Nibbler::System::AutoTurnSystem::checkBodyCollision(const Arcade::Vector2f &headPos, Arcade::ECS::IComponent &fst)
{
    Arcade::Graph::Sprite &fstS = static_cast<Arcade::Graph::Sprite&>(fst);

    if (
    (headPos.x + 5 >= fstS.pos.x + PARCELL_SIZE - 5) ||
    (headPos.x + PARCELL_SIZE - 5 < fstS.pos.x + 5) ||
    (headPos.y + 5 > fstS.pos.y + PARCELL_SIZE - 5) ||
    (headPos.y + PARCELL_SIZE - 5 < fstS.pos.y + 5)
    ) {
        return false;
    }
    return true;
}

bool Nibbler::System::AutoTurnSystem::checkAllBodiesCollision(const Arcade::Vector2f &headPos,
    std::vector<std::shared_ptr<Arcade::ECS::IEntity>> &bodies)
{
    if (bodies.size() < 2) {
        return false;
    }
    for (auto const &body : bodies) {
        if (body->getId() == NIBBLER_HEAD ||
        body->getId() == std::string(NIBBLER_BODY_PART) + "0" ||
        body->getId() == std::string(NIBBLER_BODY_PART) + "1") {
            continue;
        }
        for (auto const &bodySprite : body->getComponents(Arcade::ECS::CompType::SPRITE)) {
            if (checkBodyCollision(headPos, *bodySprite)) {
                return true;
            }
        }
    }
    return false;
}

bool Nibbler::System::AutoTurnSystem::isAbleToMove(const Arcade::Vector2f &pos,
const std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &walls,
std::vector<std::shared_ptr<Arcade::ECS::IEntity>> &bodies)
{
    if (pos.x < NIBBLER_PADDING_WINDOW_X || pos.x >= MAP_RIGHT
        || pos.y < NIBBLER_PADDING_WINDOW_Y || pos.y >= MAP_BOTTOM) {
        return false;
    }
    for (const auto &wall : walls) {
        auto sprite = std::static_pointer_cast<Nibbler::Component::NibblerWallComponent>(wall);
        if (pos.x >= sprite->pos.x && pos.x < sprite->pos.x + PARCELL_SIZE
            && pos.y >= sprite->pos.y && pos.y < sprite->pos.y + PARCELL_SIZE) {
            return false;
        }
    }
    return !checkAllBodiesCollision(pos, bodies);
}

void Nibbler::System::AutoTurnSystem::run(
double deltaTime,
Arcade::ECS::IEventManager &eventManager,
Arcade::ECS::IEntityManager &currentEntityManager)
{
    static int nb_move = 0;
    auto head = currentEntityManager.getEntitiesById(NIBBLER_HEAD);
    auto &curDir = static_cast<Component::Forward &>(head->getComponents(FORWARD_KEY));
    auto &sprite = static_cast<Arcade::Graph::ISprite &>(head->getComponents(NIBBLER_SPRITE));
    auto wallsEntity = currentEntityManager.getEntitiesById(NIBBLER_WALL_ID);
    const std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &walls = wallsEntity->getComponents(Arcade::ECS::CompType::SPRITE);
    std::vector<std::shared_ptr<Arcade::ECS::IEntity>> bodies =
    *currentEntityManager.getEntitiesByComponentType(Arcade::ECS::CompType::FORWARD);

    if (isAbleToMove(toNextCase(Arcade::Vector2f(sprite.pos.x, sprite.pos.y), curDir.direction), walls, bodies)) {
        return;
    }
    std::map<Nibbler::Direction, std::vector<std::pair<Arcade::Vector2f, Nibbler::Direction>>> nextPoss = {
        {Direction::UP,
            {
                {{sprite.pos.x - PARCELL_SIZE, sprite.pos.y}, {Direction::LEFT}},
                {{sprite.pos.x + PARCELL_SIZE, sprite.pos.y}, {Direction::RIGHT}}
            }
        },
        {Direction::DOWN,
            {
                {{sprite.pos.x - PARCELL_SIZE, sprite.pos.y}, {Direction::LEFT}},
                {{sprite.pos.x + PARCELL_SIZE, sprite.pos.y}, {Direction::RIGHT}}
            }
        },
        {Direction::LEFT,
            {
                {{sprite.pos.x, sprite.pos.y - PARCELL_SIZE}, {Direction::UP}},
                {{sprite.pos.x, sprite.pos.y + PARCELL_SIZE}, {Direction::DOWN}}
            }
        },
        {Direction::RIGHT,
            {
                {{sprite.pos.x, sprite.pos.y - PARCELL_SIZE}, {Direction::UP}},
                {{sprite.pos.x, sprite.pos.y + PARCELL_SIZE}, {Direction::DOWN}}
            }
        }
    };
    for (auto const &nextPos : nextPoss[curDir.direction]) {
        if (isAbleToMove(nextPos.first, walls, bodies)) {
            head->addComponent(std::make_shared<Component::ChangeDir>(
            MOVE_INPUT_COMPS_AUTOTURN + std::to_string(++nb_move),
            nextPos.second,
            toNextCase(
            Arcade::Vector2f(sprite.pos.x, sprite.pos.y), nextPos.second)));
            return;
        }
    }
    eventManager.addEvent(RESTART_EVENT);
}
