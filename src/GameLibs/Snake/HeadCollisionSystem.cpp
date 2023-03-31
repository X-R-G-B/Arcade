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
   std::unique_ptr<std::vector<std::shared_ptr<IComponent>>> headv = currentScene.getComponentsByComponentType(SNAKE_HEAD);
   std::unique_ptr<std::vector<std::shared_ptr<IComponent>>> bodies = currentScene.getComponentsByComponentType(SNAKE_BODY);
   std::shared_ptr<IComponent> head = headv.get().front();

    for (auto const &body : bodies.get()) {
        if ()
    }
}