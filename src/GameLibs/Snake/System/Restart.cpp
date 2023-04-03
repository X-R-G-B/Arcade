/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EntryPoint
*/

#include "Restart.hpp"
#include "MagicValue.hpp"

Snake::System::Restart::Restart(std::unique_ptr<Arcade::Game::IScene> &scene) : _scene(scene)
{
}

void Snake::System::Restart::run(float deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    if (eventManager.isEventTriggered(RESTART_EVENT).first) {
        _scene->close();
        _scene->init();
    }
}
