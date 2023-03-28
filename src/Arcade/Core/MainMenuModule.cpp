/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MainMenuModule
*/

#include "EntityManager.hpp"
#include "MainMenuModule.hpp"

Arcade::Core::MainMenuModule::MainMenuModule(
    const std::vector<std::pair<std::string, std::string>> &gameLibs,
    const std::vector<std::pair<std::string, std::string>> &graphicLibs
)
    : _mainMenu(std::make_unique<MainMenuScene>(std::make_unique<Arcade::ECS::EntityManager>(), gameLibs, graphicLibs)),
     _systemManager(std::make_unique<Arcade::ECS::SystemManager>())
{
    _mainMenu->init();
}

Arcade::Core::MainMenuModule::~MainMenuModule()
{
}

void Arcade::Core::MainMenuModule::update(float deltaTime, Arcade::ECS::IEventManager &eventManager)
{
    _systemManager->update(deltaTime, eventManager, _mainMenu->getEntityManager());
    if (eventManager.isEventTriggered("KEY_UP_PRESSED").first) {
        std::cout << "Change game lib" << std::endl;
    }
    if (eventManager.isEventTriggered("KEY_DOWN_PRESSED").first) {
        std::cout << "Change graph lib" << std::endl;
    }
}

Arcade::ECS::IEntityManager &Arcade::Core::MainMenuModule::getCurrentEntityManager()
{
    return (_mainMenu->getEntityManager());
}
