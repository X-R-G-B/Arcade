/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** GameModule code
*/

#include "Core.hpp"
#include "GameModule.hpp"
#include "LibHandler.hpp"

Arcade::Core::GameModule::GameModule(std::vector<std::string> libsNames) : _sceneManager(nullptr), _libsNames(libsNames), _currentLib("")
{
}

std::unique_ptr<Arcade::Game::ISceneManager> &Arcade::Core::GameModule::getSceneManager()
{
    return _sceneManager;
}

void Arcade::Core::GameModule::changeGame(const std::string &gameName)
{

}

void Arcade::Core::GameModule::changeGame()
{
    if (_currentLib == "" && _libsNames.size() > 0) {
        _currentLib = _libsNames.front();
    }
    
}

void Arcade::Core::GameModule::loadGame(const std::string &gameName)
{
    std::string path = Core::libPathStart + gameName + Core::libPathEnd;

    
}

std::vector<std::string> Arcade::Core::GameModule::getGamesNames()
{
    return _libsNames;
}

bool isGameLoaded()
{
    if 
}
