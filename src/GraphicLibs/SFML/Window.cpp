/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml Window
*/

#include "Window.hpp"

Arcade::Sfml::Window::Window()
{
    win = sf::Window::Window(sf::VideoMode(800, 600), "SFML window");
    window.setFramerateLimit(60);
}

Arcade::Sfml::Window::update(float delta, Arcade::ECS::IEventManager &eventManager,
        Arcade::ECS::IEntityManager &entityManager)
{
    win.display();
}
