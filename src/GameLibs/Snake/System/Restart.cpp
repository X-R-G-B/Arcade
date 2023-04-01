/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EntryPoint
*/

#include "Restart.hpp"

Snake::System::Restart::Restart(Arcade::Game::IScene &scene) : _scene(scene)
{
}

void Snake::System::Restart::run(float deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    eventManager.isEventTriggered("RESTART");

}
