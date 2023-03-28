/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml
*/

#include "Api.hpp"
#include "Sfml.hpp"
#include "Text.hpp"

Arcade::Sfml::DisplayModule::DisplayModule()
{
    _win.create(sf::VideoMode(800, 600), "window");
    _win.setFramerateLimit(60);
    _systems.addSystem("textSystem", std::make_unique<TextSystem>(_win));
}

void Arcade::Sfml::DisplayModule::update(float delta, Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &entityManager)
{
    _systems.update(delta, eventManager, entityManager);
    _win.display();
}

LibType getType()
{
    return LibType::GRAPH;
}

const char *getName()
{
    return "sfml";
}

Arcade::Graph::IDisplayModule *getDisplayModule()
{
    return new Arcade::Sfml::DisplayModule();
}

void destroyDisplayModule(Arcade::Graph::IDisplayModule *mod)
{
    delete mod;
}