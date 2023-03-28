/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFML_EventHandler
*/

#include "SFML_EventHandler.hpp"

SFML_EventHandler::SFML_EventHandler()
    : _windowSize(0, 0)
{}

void SFML_EventHandler::run(float deltaTime,
Arcade::ECS::IEventManager &eventManager,
Arcade::ECS::IEntityManager &currentScene)
{
    for (auto &key : KeyboardKeys) {
        if (sf::Keyboard::isKeyPressed(key.first)) {
            eventManager.addEvent(key.second);
        }
    }

}
