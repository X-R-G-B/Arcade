/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MainMenuModule
*/

#include "EntityManager.hpp"
#include "LibHandler.hpp"
#include "MainMenuModule.hpp"

Arcade::Core::MainMenuModule::MainMenuModule(
    const std::vector<std::pair<std::string, std::string>> &gameLibs,
    const std::vector<std::pair<std::string, std::string>> &graphicLibs,
    const std::string &currentGameLib,
    const std::string &currentGraphicLib
)
    : _mainMenu(std::make_unique<MainMenuScene>(
        std::make_unique<Arcade::ECS::EntityManager>(),
        gameLibs, graphicLibs, currentGameLib, currentGraphicLib)),
     _systemManager(std::make_unique<Arcade::ECS::SystemManager>())
{
    _mainMenu->init();
}

Arcade::Core::MainMenuModule::~MainMenuModule()
{
}

void Arcade::Core::MainMenuModule::update(double deltaTime, Arcade::ECS::IEventManager &eventManager)
{
    _systemManager->update(deltaTime, eventManager, _mainMenu->getEntityManager());
    if (eventManager.isEventTriggered("KEY_UP_PRESSED").first) {
        eventManager.addEvent("CHANGE_GAME");
    }
    if (eventManager.isEventTriggered("KEY_DOWN_PRESSED").first) {
        eventManager.addEvent("CHANGE_GRAPH");
    }
}

Arcade::ECS::IEntityManager &Arcade::Core::MainMenuModule::getCurrentEntityManager()
{
    return (_mainMenu->getEntityManager());
}
