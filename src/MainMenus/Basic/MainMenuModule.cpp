/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MainMenuModule
*/

#include <memory>
#include "EntityManager.hpp"
#include "LibHandler.hpp"
#include "MainMenuModule.hpp"
#include "MainMenuScene.hpp"
#include "MainMenuSystem.hpp"

BasicMenu::MainMenuModule::MainMenuModule(Arcade::MainMenu::Context *context):
    _scene(context), _context(context)
{
    _scene.init();
    _systemManager.addSystem("MainMenu", std::make_unique<BasicMenu::MainMenuSystem>(_context));
}

BasicMenu::MainMenuModule::~MainMenuModule()
{
    _scene.close();
}

void BasicMenu::MainMenuModule::update(double deltaTime, Arcade::ECS::IEventManager &eventManager, Arcade::MainMenu::Context *context)
{
    _systemManager.update(deltaTime, eventManager, _scene.getEntityManager());
    if (eventManager.isEventTriggered("KEY_1_PRESSED").first) {
        eventManager.addEvent("CHANGE_GAME");
    }
    if (eventManager.isEventTriggered("KEY_2_PRESSED").first) {
        eventManager.addEvent("CHANGE_GRAPH");
    }
}

Arcade::ECS::IEntityManager &BasicMenu::MainMenuModule::getCurrentEntityManager()
{
    return (_scene.getEntityManager());
}
