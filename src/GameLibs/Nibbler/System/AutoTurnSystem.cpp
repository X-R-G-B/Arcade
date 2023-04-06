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
#include "NibblerWallComponent.hpp"
#include "AutoTurnSystem.hpp"

Arcade::Vector2f Nibbler::System::AutoTurnSystem::toNextCase(const Arcade::Vector3f &pos, const Nibbler::Direction &direction)
{
    int caseCurX = (TO_INT(pos.x) - SNAKE_PADDING_WINDOW_X) / PARCELL_SIZE;
    int caseCurY = (TO_INT(pos.y) - SNAKE_PADDING_WINDOW_Y) / PARCELL_SIZE;

    if (direction == Direction::UP) {
        return {pos.x, caseCurY * TO_FLOAT(PARCELL_SIZE) + SNAKE_PADDING_WINDOW_Y};
    } else if (direction == Direction::DOWN) {
        caseCurY = (TO_INT(pos.y) + PARCELL_SIZE - SNAKE_PADDING_WINDOW_Y) / PARCELL_SIZE;
        return {pos.x, caseCurY * TO_FLOAT(PARCELL_SIZE) + SNAKE_PADDING_WINDOW_Y};
    } else if (direction == Direction::LEFT) {
        return {caseCurX * TO_FLOAT(PARCELL_SIZE) + SNAKE_PADDING_WINDOW_X, pos.y};
    } else if (direction == Direction::RIGHT) {
        caseCurX = (TO_INT(pos.x) + PARCELL_SIZE - SNAKE_PADDING_WINDOW_X) / PARCELL_SIZE;
        return {caseCurX * TO_FLOAT(PARCELL_SIZE) + SNAKE_PADDING_WINDOW_X, pos.y};
    }
    return {pos.x, pos.y};
}

bool Nibbler::System::AutoTurnSystem::isAbleToMove(const Arcade::Vector2f &pos, const std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &walls)
{
    for (const auto &wall : walls) {
        auto sprite = std::static_pointer_cast<Nibbler::Component::NibblerWallComponent>(wall);
        if (pos.x >= sprite->pos.x && pos.x < sprite->pos.x + PARCELL_SIZE
            && pos.y >= sprite->pos.y && pos.y < sprite->pos.y + PARCELL_SIZE) {
            return true;
        }
    }
    return true;
}

void Nibbler::System::AutoTurnSystem::run(
double deltaTime,
Arcade::ECS::IEventManager &eventManager,
Arcade::ECS::IEntityManager &currentEntityManager)
{
    auto head = currentEntityManager.getEntitiesById(NIBBLER_HEAD);
    auto &curDir = static_cast<Component::Forward &>(head->getComponents(FORWARD_KEY));
    auto &sprite = static_cast<Arcade::Graph::ISprite &>(head->getComponents(NIBBLER_SPRITE));
    auto wallsEntity = currentEntityManager.getEntitiesById(NIBBLER_WALL_ID);
    const std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &walls = nibblerWalls.getComponents(Arcade::ECS::CompType::SPRITE);
    bool isMoved = false;

    if (eventManager.isEventTriggered(COLLISION_EVENT).first) {
        return;
    }
    switch (curDir.direction) {
        case Direction::UP || Direction::DOWN:
            if (isAbleToMove(Arcade::Vector2f(sprite.pos.x - PARCELL_SIZE, sprite.pos.y), walls)) {
                head->addComponent(std::make_shared<Component::ChangeDir>(
                MOVE_INPUT_COMPS + std::to_string(++nb_move), Direction::LEFT,
                toNextCase(sprite.pos, curDir.direction)));
                isMoved = true;
            } else if (isAbleToMove(Arcade::Vector2f(sprite.pos.x + PARCELL_SIZE, sprite.pos.y), walls)) {
                head->addComponent(std::make_shared<Component::ChangeDir>(
                MOVE_INPUT_COMPS + std::to_string(++nb_move), Direction::RIGHT,
                toNextCase(sprite.pos, curDir.direction)));
                isMoved = true;
            }
            break;
        case Direction::LEFT || Direction::RIGHT:
            if (isAbleToMove(Arcade::Vector2f(sprite.pos.x, sprite.pos.y - PARCELL_SIZE), walls)) {
                head->addComponent(std::make_shared<Component::ChangeDir>(
                MOVE_INPUT_COMPS + std::to_string(++nb_move), Direction::UP,
                toNextCase(sprite.pos, curDir.direction)));
                isMoved = true;
            } else if (isAbleToMove(Arcade::Vector2f(sprite.pos.x, sprite.pos.y + PARCELL_SIZE), walls)) {
                head->addComponent(std::make_shared<Component::ChangeDir>(
                MOVE_INPUT_COMPS + std::to_string(++nb_move), Direction::DOWN,
                toNextCase(sprite.pos, curDir.direction)));
                isMoved = true;
            }
            break;
    }
    if (!isMoved) {
        eventManager.addEvent(RESTART_EVENT);
    }
}
