/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml Window
*/

#include "Window.hpp"

Arcade::Sfml::Window::Window(): _win(sf::VideoMode(800, 600), "SFML window")
{
    _win.setFramerateLimit(60);
}

void Arcade::Sfml::Window::run(float delta, Arcade::ECS::IEventManager &eventManager,
        Arcade::ECS::IEntityManager &entityManager)
{
   _win.display();
}
