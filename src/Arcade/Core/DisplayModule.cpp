/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** DisplayModule
*/

#include <algorithm>
#include "DisplayModule.hpp"

Arcade::Core::DisplayModule::DisplayModule(std::vector<std::string> libsNames) : Module(libsNames), _systemManager(nullptr), _windowSize({0, 0})
{
}

std::shared_ptr<Arcade::ECS::ISystemManager> Arcade::Core::DisplayModule::getSystemManager()
{
    return _systemManager;
}

void Arcade::Core::DisplayModule::changeGraphicLib(const std::string &libGraphicName)
{
    _currentLib = libGraphicName;
    loadGraphicLib(_currentLib);
}


void Arcade::Core::DisplayModule::changeGraphicLib()
{
    changelib();
    loadGraphicLib(_currentLib);
}

void Arcade::Core::DisplayModule::loadGraphicLib(const std::string &gameName)
{
    std::unique_ptr<LibHandler> libHandler = getLibHandler(gameName);

    _systemManager.reset(); // TODO add params if need when SystemManager implemented
    _systemManager = libHandler->loadMainFunction<std::shared_ptr<Arcade::ECS::ISystemManager>>("getScenes", _systemManager);
}

Arcade::Vector2f &Arcade::Core::DisplayModule::getWindowSize()
{
    return _windowSize;
}

void Arcade::Core::DisplayModule::setWindowSize(const Arcade::Vector2f &newSize)
{
    _windowSize = newSize;
}

