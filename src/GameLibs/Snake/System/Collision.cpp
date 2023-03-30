/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Collision
*/

#include "Collision.hpp"
#include "Sprite.hpp"
#include "CompType.hpp"

Snake::System::Collision::Collision()
{
}

void Snake::System::Collision::run(float deltaTime,
                              Arcade::ECS::IEventManager &eventManager,
                              Arcade::ECS::IEntityManager &currentEntityManager)
{
    std::shared_ptr<Arcade::ECS::IEntity> snakeEntity = currentEntityManager.getEntitiesById("Snake");
    std::shared_ptr<Arcade::ECS::IEntity> appleEntity = currentEntityManager.getEntitiesById("Apple");
    Arcade::ECS::IComponent &snakeHeadIComp = snakeEntity->getComponents("Snake Head");
    Arcade::ECS::IComponent &appleIComp = appleEntity->getComponents("apple");

    if (snakeHeadIComp.type == Arcade::ECS::CompType::SPRITE
        && appleIComp.type == Arcade::ECS::CompType::SPRITE) {
        Arcade::Graph::Sprite &apple = static_cast<Arcade::Graph::Sprite &>(appleIComp);
        Arcade::Graph::Sprite &snakeHead = static_cast<Arcade::Graph::Sprite &>(snakeHeadIComp);

        if (apple.rect.left >= snakeHead.rect.left + snakeHead.rect.width
            || apple.rect.left + apple.rect.width <= snakeHead.rect.left
            || apple.rect.top >= snakeHead.rect.left + snakeHead.rect.height
            || apple.rect.top + apple.rect.height <= snakeHead.rect.top) {
            eventManager.addEvent("Eated apple");
        }
    }
}
