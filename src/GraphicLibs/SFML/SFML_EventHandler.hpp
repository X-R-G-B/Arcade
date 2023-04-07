/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFML_EventHandler
*/

#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "ISystem.hpp"

class SFML_EventHandler : public Arcade::ECS::ISystem {
    public:
        SFML_EventHandler(sf::RenderWindow &window);
        ~SFML_EventHandler() = default;

        void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentScene) final;

    protected:
    private:
        sf::Vector2u _windowSize;
        sf::RenderWindow &_window;
};
