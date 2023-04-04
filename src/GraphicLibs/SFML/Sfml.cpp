/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml
*/

#include "Api.hpp"
#include "Sfml.hpp"
#include "Text.hpp"
#include "Sprite.hpp"
#include "Music.hpp"
#include "SFML_EventHandler.hpp"

Arcade::Sfml::DisplayModule::DisplayModule()
{
    _win.create(sf::VideoMode(1920, 1080), "window");
    _win.setFramerateLimit(60);
    _systems.addSystem("musicSystem", std::make_unique<MusicSystem>(_win, _components));
    _systems.addSystem("spriteSystem", std::make_unique<SpriteSystem>(_win, _components));
    _systems.addSystem("textSystem", std::make_unique<TextSystem>(_win, _components));
    _systems.addSystem("eventHander", std::make_unique<SFML_EventHandler>(_win));
}

Arcade::Sfml::DisplayModule::~DisplayModule()
{
    _win.close();
}

void Arcade::Sfml::DisplayModule::update(double delta, Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &entityManager)
{
    _win.clear();
    _systems.update(delta, eventManager, entityManager);
    _win.display();
}

extern "C" LibType getType()
{
    return LibType::GRAPH;
}

extern "C" const char *getName()
{
    return "sfml";
}

extern "C" Arcade::Graph::IDisplayModule *getDisplayModule()
{
    return new Arcade::Sfml::DisplayModule();
}

extern "C" void destroyDisplayModule(Arcade::Graph::IDisplayModule *mod)
{
    delete mod;
}
