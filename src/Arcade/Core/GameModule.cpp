/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** GameModule code
*/

#include "Core.hpp"
#include "GameModule.hpp"

Arcade::Core::GameModule::GameModule(std::vector<std::string> libsNames) : Module(libsNames), _sceneManager(nullptr)
{
}

std::shared_ptr<Arcade::Game::ISceneManager> Arcade::Core::GameModule::getSceneManager()
{
    return _sceneManager;
}

void Arcade::Core::GameModule::changeGame(const std::string &gameName)
{
    _currentLib = gameName;
    loadGame(gameName);
}

void Arcade::Core::GameModule::changeGame()
{
    changelib();
    loadGame(_currentLib);
}

std::shared_ptr<Arcade::ECS::IEventManager> Arcade::Core::GameModule::getGameEventManager()
{
    return _eventManager;
}

void Arcade::Core::GameModule::loadGame(const std::string &gameName)
{
    std::unique_ptr<LibHandler> libHandler = getLibHandler(gameName);

    _sceneManager.reset(); // TODO add params if need when SceneManager implemented
    _sceneManager = libHandler->loadMainFunction<std::shared_ptr<Arcade::Game::ISceneManager>>("getScenes", _sceneManager);
}

std::vector<std::string> &Arcade::Core::GameModule::getGamesNames()
{
    return _libsNames;
}
