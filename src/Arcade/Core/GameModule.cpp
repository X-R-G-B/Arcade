/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** GameModule code
*/

#include "GameModule.hpp"

Arcade::Core::GameModule::GameModule(std::vector<std::string> libsNames) : _sceneManager(nullptr), _libsNames(libsNames), _currentLib("")
{
}

std::unique_ptr<Arcade::Game::ISceneManager> &Arcade::Core::GameModule::getSceneManager()
{
    return _sceneManager;
}

void Arcade::Core::GameModule::changeGame(const std::string &gameName)
{
    if (_currentLib == "" && _libsNames.size() > 0) {
        _currentLib = _libsNames.front();
    }

}

void Arcade::Core::GameModule::changeGame()
{

}

