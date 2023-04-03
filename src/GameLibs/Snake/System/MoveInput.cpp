/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake Move System
*/

#include <map>
#include <string>
#include <utility>
#include <vector>
#include "ArcadeStruct.hpp"
#include "ISprite.hpp"
#include "Direction.hpp"
#include "Forward.hpp"
#include "MoveInput.hpp"
#include "MagicValue.hpp"
#include "ChangeDir.hpp"

static const std::map<Snake::Direction, std::vector<std::pair<std::string, Snake::Direction>>>
directionsChoice = {
    {
        Snake::Direction::UP, {
            std::make_pair("KEY_LEFT_PRESSED", Snake::Direction::LEFT),
            std::make_pair("KEY_RIGHT_PRESSED", Snake::Direction::RIGHT),
        }
    },
    {
        Snake::Direction::DOWN, {
            std::make_pair("KEY_LEFT_PRESSED", Snake::Direction::LEFT),
            std::make_pair("KEY_RIGHT_PRESSED", Snake::Direction::RIGHT),
        }
    },
    {
        Snake::Direction::RIGHT, {
            std::make_pair("KEY_UP_PRESSED", Snake::Direction::UP),
            std::make_pair("KEY_DOWN_PRESSED", Snake::Direction::DOWN),
        }
    },
    {
        Snake::Direction::LEFT, {
            std::make_pair("KEY_UP_PRESSED", Snake::Direction::UP),
            std::make_pair("KEY_DOWN_PRESSED", Snake::Direction::DOWN),
        }
    }
};

Arcade::Vector2f Snake::System::MoveInput::toNextCase(const Arcade::Vector3f &pos, const Snake::Direction &direction)
{
    int caseCurX = TO_INT(pos.x) % TO_INT(CASE_SIZE_WIDTH);
    int caseCurY = TO_INT(pos.y) % TO_INT(CASE_SIZE_HEIGHT);

    switch (direction) {
        case Snake::Direction::UP:
            return {pos.x, caseCurY * CASE_SIZE_HEIGHT};
        case Snake::Direction::DOWN:
            caseCurY = TO_INT(pos.y + CASE_SIZE_HEIGHT) % TO_INT(CASE_SIZE_HEIGHT);
            return {pos.x, caseCurY * CASE_SIZE_HEIGHT};
        case Snake::Direction::LEFT:
            return {caseCurX * CASE_SIZE_WIDTH, pos.y};
        case Snake::Direction::RIGHT:
            caseCurX = TO_INT(pos.x + CASE_SIZE_WIDTH) % TO_INT(CASE_SIZE_WIDTH);
            return {caseCurX * CASE_SIZE_WIDTH, pos.y};
        default:
            return {pos.x, pos.y};
    }
}

void Snake::System::MoveInput::run(
    float deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    static int nb_move = 0;
    auto head = currentEntityManager.getEntitiesById(SNAKE_HEAD);
    auto &curDir = static_cast<Component::Forward &>(head->getComponents(FORWARD_KEY));
    auto &sprite = static_cast<Arcade::Graph::ISprite &>(head->getComponents(SNAKE_HEAD_SPRITE_COMP));

    for (auto &[event, action] : directionsChoice.at(curDir.direction)) {
        if (eventManager.isEventTriggered(event).first) {
            head->addComponent(std::make_shared<Component::ChangeDir>(
                MOVE_INPUT_COMPS + std::to_string(++nb_move),
                action,
                toNextCase(sprite.pos, curDir.direction)
            ));
            break;
        }
    }
}
