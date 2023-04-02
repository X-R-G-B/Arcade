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
#include "SnakeGrow.hpp"

void Snake::System::EatSystem::run(float deltaTime,
                              Arcade::ECS::IEventManager &eventManager,
                              Arcade::ECS::IEntityManager &currentEntityManager)
{
    auto snakeEntity = currentEntityManager.getEntitiesById(SNAKE);
    auto &snakeIncrIComp = snakeEntity->getComponents(SNAKE_GROW_COMPONENT);

    if (snakeIncrIComp.type == Arcade::ECS::CompType::SNAKEGROW) {
        auto &snakeIncrComp = static_cast<Snake::Component::SnakeGrow &>(snakeIncrIComp);
        if (eventManager.isEventTriggered(EATED_EVENT).first) {
            snakeIncrComp.grow += 1;
            //TODO increment the score when implemented
        }
    }
}
