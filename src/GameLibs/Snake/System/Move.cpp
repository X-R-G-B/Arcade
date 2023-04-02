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
#include "Direction.hpp"
#include "Move.hpp"
#include "MagicValue.hpp"
#include "Moveable.hpp"

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
    }
};

Snake::System::Move::Move(const Direction &snakeDirection):
    _snakeDirection(snakeDirection)
{
}

void Snake::System::Move::run(
    float deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    static int nb_move = 0;

    for (auto &[event, action] : directionsChoice.at(_snakeDirection)) {
        if (eventManager.isEventTriggered(event).first) {
            auto head = currentEntityManager.getEntitiesById(SNAKE_HEAD);
            head->addComponent(std::make_shared<Component::Moveable>(
                "SNAKE_MOVE" + std::to_string(++nb_move), _snakeDirection)
            );
            break;
        }
    }
}
