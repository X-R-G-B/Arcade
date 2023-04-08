/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EntryPoint
*/

#include "NibblerCompType.hpp"
#include "Restart.hpp"
#include "MagicValue.hpp"

Nibbler::System::Restart::Restart(std::unique_ptr<Arcade::Game::IScene> &scene) : _scene(scene)
{
}

void Nibbler::System::Restart::run(double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    if (!eventManager.isEventTriggered(RESTART_EVENT).first) {
        return;
    }
    _scene->close();
    _scene->init();
}
