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
    auto snakeEntity = currentEntityManager.getEntitiesById(SNAKE_ENTITY);
    auto &snakeIncrComp = snakeEntity->getComponents(SNAKE_INCR_COMP);

    if (snakeIncrComp.type == Arcade::ECS::CompType::SPRITE) {
        //if (eventManager.isEventTriggered(EATED).first) { The if condition will work when EATED will be defined
            //TODO incr the data of snakeIncrComp + 1
        //}
    }
}
