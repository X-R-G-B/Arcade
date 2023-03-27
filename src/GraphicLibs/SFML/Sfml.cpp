/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml
*/

#include "Sfml.hpp"
#include "Window.hpp"

Arcade::Sfml::DisplayModule::DisplayModule()
{
    _systems.addSystem("TextSystem", std::make_unique<TextSystem>());
    _systems.addSystem("window", std::make_unique<ECS::>());
}

void Arcade::Sfml::DisplayModule::update(float delta, Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &entityManager)
{
    _systems.update(delta, eventManager, entityManager);
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
