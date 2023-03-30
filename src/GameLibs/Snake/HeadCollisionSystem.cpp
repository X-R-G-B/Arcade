/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFML_EventHandler
*/

#include "HeadCollisionSystem.hpp"

void Snake::HeadCollisionSystem::run(float deltaTime, Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentScene)
{
   std::unique_ptr<std::vector<std::shared_ptr<IComponent>>> = currentScene.getComponentsByComponentType(SNAKE_HEAD);
   std::unique_ptr<std::vector<std::shared_ptr<IComponent>>> = currentScene.getComponentsByComponentType(SNAKE_BODY);
}