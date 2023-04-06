/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake Move System
*/

#include <map>
#include <string>
#include <vector>
#include "ArcadeStruct.hpp"
#include "ISprite.hpp"
#include "Direction.hpp"
#include "Forward.hpp"
#include "MoveInput.hpp"
#include "MagicValue.hpp"
#include "ChangeDir.hpp"

#include <iostream>
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
    int caseCurX = (TO_INT(pos.x) - SNAKE_PADDING_WINDOW_X) / PARCELL_SIZE;
    int caseCurY = (TO_INT(pos.y) - SNAKE_PADDING_WINDOW_Y) / PARCELL_SIZE;

    if (direction == Direction::UP) {
        return {pos.x, caseCurY * TO_FLOAT(PARCELL_SIZE) - PARCELL_SIZE / 2 + SNAKE_PADDING_WINDOW_Y};
    } else if (direction == Direction::DOWN) {
        caseCurY = TO_INT(pos.y) + PARCELL_SIZE - SNAKE_PADDING_WINDOW_Y / PARCELL_SIZE;
        return {pos.x, caseCurY * TO_FLOAT(PARCELL_SIZE) + PARCELL_SIZE / 2 + SNAKE_PADDING_WINDOW_Y};
    } else if (direction == Direction::LEFT) {
        return {caseCurX * TO_FLOAT(PARCELL_SIZE) - PARCELL_SIZE / 2 + SNAKE_PADDING_WINDOW_X, pos.y};
    } else if (direction == Direction::RIGHT) {
        caseCurX = TO_INT(pos.x) + PARCELL_SIZE - SNAKE_PADDING_WINDOW_X / PARCELL_SIZE;
        return {caseCurX * TO_FLOAT(PARCELL_SIZE) + PARCELL_SIZE / 2 + SNAKE_PADDING_WINDOW_X, pos.y};
    }
    return {pos.x, pos.y};
}

void Snake::System::MoveInput::run(
    double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    static int nb_move = 0;
    auto head = currentEntityManager.getEntitiesById(SNAKE_HEAD);
    auto &curDir = static_cast<Component::Forward &>(head->getComponents(FORWARD_KEY));
    auto &sprite = static_cast<Arcade::Graph::ISprite &>(head->getComponents(SNAKE_SPRITE));

    for (auto &[event, action] : directionsChoice.at(curDir.direction)) {
        if (eventManager.isEventTriggered(event).first) {
            auto pos = toNextCase(sprite.pos, curDir.direction);
            head->addComponent(std::make_shared<Component::ChangeDir>(
                MOVE_INPUT_COMPS + std::to_string(++nb_move),
                action,
                toNextCase(sprite.pos, curDir.direction)
            ));
            break;
        }
    }
}
