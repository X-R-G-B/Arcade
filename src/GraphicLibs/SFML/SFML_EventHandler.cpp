/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFML_EventHandler
*/

#include "SFML_EventHandler.hpp"

SFML_EventHandler::SFML_EventHandler(sf::RenderWindow &window) : _window(window)
{
    this->_windowSize = this->_window.getSize();
}

void SFML_EventHandler::run(float deltaTime,
Arcade::ECS::IEventManager &eventManager,
Arcade::ECS::IEntityManager &currentScene)
{
    auto windowSize = this->_window.getSize();

    if (this->_windowSize != windowSize) {
        this->_windowSize = windowSize;
        eventManager.addEvent("WINDOW_RESIZE");
    }
    for (auto &key : KeyboardKeys) {
        if (sf::Keyboard::isKeyPressed(key.first)) {
            eventManager.addEvent(key.second);
        }
    }
}
