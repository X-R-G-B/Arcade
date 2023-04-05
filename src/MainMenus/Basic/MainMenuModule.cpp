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
#include "MainMenus/Basic/MainMenuScene.hpp"

BasicMenu::MainMenuModule::MainMenuModule(Arcade::MainMenu::Context *context):
    _scene(context), _context(context)
{
}

BasicMenu::MainMenuModule::~MainMenuModule()
{
}

void BasicMenu::MainMenuModule::update(double deltaTime, Arcade::ECS::IEventManager &eventManager, Arcade::MainMenu::Context *context)
{
    _systemManager.update(deltaTime, eventManager, _scene.getEntityManager());
    if (eventManager.isEventTriggered("KEY_UP_PRESSED").first) {
        eventManager.addEvent("CHANGE_GAME");
    }
    if (eventManager.isEventTriggered("KEY_DOWN_PRESSED").first) {
        eventManager.addEvent("CHANGE_GRAPH");
    }
}

Arcade::ECS::IEntityManager &BasicMenu::MainMenuModule::getCurrentEntityManager()
{
    return (_scene.getEntityManager());
}
