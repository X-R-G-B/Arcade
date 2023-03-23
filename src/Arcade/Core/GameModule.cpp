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

std::unique_ptr<Arcade::Game::ISceneManager> &Arcade::Core::GameModule::getSceneManager()
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
    if (_currentLib == "" && _libsNames.size() > 0) {
        _currentLib = _libsNames.front();
    } else {
        nextLib();
    }
    loadGame(_currentLib);
}

void Arcade::Core::GameModule::loadGame(const std::string &gameName)
{
    std::unique_ptr<LibHandler> libHandler = getLibHandler(gameName);

    _sceneManager = libHandler->loadFunction<std::unique_ptr<Arcade::Game::ISceneManager>>("getScenes");
}

std::vector<std::string> Arcade::Core::GameModule::getGamesNames()
{
    return _libsNames;
}

bool Arcade::Core::GameModule::isGameLoaded()
{
    if (_sceneManager.get() == nullptr) {
        return false;
    }
    return true;
}
