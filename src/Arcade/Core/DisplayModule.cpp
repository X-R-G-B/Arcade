/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** DisplayModule
*/

#include <iostream>
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
    if (_currentLib.empty()) {
        //TODO custom exception
        throw std::invalid_argument("No graphic shared lib in lib/");
    }
    loadGraphicLib(_currentLib);
}

void Arcade::Core::DisplayModule::loadGraphicLib(const std::string &libName)
{
    std::unique_ptr<LibHandler> libHandler = getLibHandler(libName);

    _systemManager.reset(); // TODO add params if need when SystemManager implemented
    std::cout << libName << std::endl;
    //_systemManager = libHandler->loadMainFunction<std::shared_ptr<Arcade::ECS::ISystemManager>>("getScenes", _systemManager);
}

void Arcade::Core::DisplayModule::addComponent(std::shared_ptr<ECS::IComponent> component)
{
    ComponentManager::addComponent(component);
}

void Arcade::Core::DisplayModule::removeComponent(const std::string &componentId)
{
    ComponentManager::removeComponent(componentId);
}

std::optional<std::shared_ptr<Arcade::ECS::IComponent>> Arcade::Core::DisplayModule::getComponent(const std::string &componentId) const
{
    return ComponentManager::getComponent(componentId);
}

const std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &Arcade::Core::DisplayModule::getComponents(ECS::CompType type) const
{
    return ComponentManager::getComponents(type);
}

const Arcade::Vector2f &Arcade::Core::DisplayModule::getWindowSize()
{
    return _windowSize;
}

void Arcade::Core::DisplayModule::setWindowSize(const Arcade::Vector2f &newSize)
{
    _windowSize = newSize;
}

