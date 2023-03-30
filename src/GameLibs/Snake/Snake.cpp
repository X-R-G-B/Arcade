/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake
*/

#include "Snake.hpp"

Snake::Snake::Snake() : _scene(std::make_unique<Arcade::ECS::IEntityManager>())
{
    _scene.init();
}

void Snake::Snake::update(float deltaTime, Arcade::ECS::IEventManager &eventManager)
{
    _systemManager.update(deltaTime, eventManager, getCurrentEntityManager());
}

Arcade::ECS::IEntityManager &Snake::Snake::getCurrentEntityManager()
{
    return _scene.getEntityManager();
}
