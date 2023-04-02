/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EatSystem
*/

#include "EatSystem.hpp"
#include "SnakeCompType.hpp"
#include "Sprite.hpp"
#include "MagicValue.hpp"

Snake::System::EatSystem::EatSystem()
{
}

void Snake::System::EatSystem::run(float deltaTime,
                              Arcade::ECS::IEventManager &eventManager,
                              Arcade::ECS::IEntityManager &currentEntityManager)
{
    auto snakeEntity = currentEntityManager.getEntitiesById(SNAKE);
    auto &snakeIncrComp = snakeEntity->getComponents("snakegrow");

    if (snakeIncrComp.type == Arcade::ECS::CompType::SNAKEGROW) {
        if (eventManager.isEventTriggered(EATED).first) {
            snakeIncrComp.grow += 1;
            //TODO increment the score when implemented
        }
    }
}
