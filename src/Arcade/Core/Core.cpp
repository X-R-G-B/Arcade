/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Core code
*/

#include <iostream>
#include <functional>
#include <filesystem>
#include <stdexcept>
#include <chrono>
#include "Api.hpp"
#include "Core.hpp"
#include "EventManager.hpp"
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

Arcade::Core::Core::Core(const std::string &path) : _gameModule(nullptr), _displayModule(nullptr)
{
    getSharedLibsNames();
    if (path.empty()) {
        changeLib(LibType::GRAPH);
    } else {
        loadGraphicLibFromPath(path);
    }
}

void Arcade::Core::Core::addNameToList(LibType type, LibHandler &LibHandler)
{
    std::string name;
 
    name = LibHandler.loadFunction<std::string>("getName");
    if (type == LibType::GAME) {
        _gamesNames.push_back(name);
    } else {
        _graphicLibsNames.push_back(name);
    }
}

void Arcade::Core::Core::getSharedLibsNames()
{
    std::size_t pos;
    LibHandler LibHandler;
    LibType type;
    std::string path;
    bool empty = true;

    for (const auto &entry : std::filesystem::directory_iterator(libFolderPath)) {
        if (empty == true) {
            empty = false;
        }
        path = std::string(entry.path());
        pos = path.find(".so");
        if (pos == std::string::npos || pos + 3 != path.length()) {
            throw std::invalid_argument("File is not a shared library: " + path);
        }
        LibHandler.loadLib(path);
        type = LibHandler.loadFunction<LibType>("getType");
        addNameToList(type, LibHandler);
    }
    if (empty) {
        throw std::invalid_argument("Empty lib folder");
    }
}

void Arcade::Core::Core::loadGraphicLibFromPath(const std::string &path)
{
    LibHandler LibHandler;
    std::size_t start = path.find("arcade_");
    std::size_t end = path.find(".so");
    LibType type;

    if (start == std::string::npos || end == std::string::npos) {
        throw std::invalid_argument("Invalid path");
    }
    LibHandler.loadLib(path);
    type = LibHandler.loadFunction<LibType>("getType");
    if (type == LibType::GAME) {
        throw std::invalid_argument("Wrong shared library type, you must load a graphic lib");
    }
    _currentGraphicLib = path.substr(start + 7, end);
    changeLib(LibType::GRAPH);
}

void Arcade::Core::Core::update()
{
    Arcade::ECS::EventManager eventManager;
    std::chrono::_V2::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::chrono::duration<double> delta(0);
    //std::unique_ptr<IScene> mainMenu = getMainMenu() TODO need main menu

    while (eventManager.isEventTriggered("QUIT").first) {
        delta = start - std::chrono::steady_clock::now();
        if (_gameModule == nullptr) {
          //mainMenu->getSystemManager->update(delta.count(), eventManager, _displayModule, _gameModule)
        } else {
            _gameModule->update(delta.count(), eventManager);
        }
        checkChangeLib(eventManager);
        eventManager.clearEvents();
        _displayModule->update(delta.count(), eventManager, _gameModule->getCurrentEntityManager());
        start = std::chrono::steady_clock::now();
    }
}

void Arcade::Core::Core::checkChangeLib(ECS::IEventManager &eventManager)
{
    if (eventManager.isEventTriggered("CHANGE_GAME").first) {
        changeLib(LibType::GAME);
        loadLib(LibType::GAME);
    } else if (eventManager.isEventTriggered("CHANGE_GRAPH").first) {
        changeLib(LibType::GRAPH);
        loadLib(LibType::GRAPH);
    }
}

void Arcade::Core::Core::loadLib(LibType type)
{
    std::unique_ptr<LibHandler> libHandler = nullptr;

    if (type == LibType::GAME) {
        libHandler = std::make_unique<LibHandler>(_currentGame);
        _gameModule.reset();
        _gameModule = libHandler->loadMainFunction<std::shared_ptr<Arcade::Game::IGameModule>>("getGameModule", _sceneManager);
    } else {
        libHandler = std::make_unique<LibHandler>(_currentGraphicLib);
        
        _displayModule = libHandler->loadMainFunction<std::shared_ptr<Arcade::Game::IDisplayModule>>("getDisplayModule", _sceneManager);
    }
}

std::unique_ptr<LibHandler> Arcade::Core::Core::getLibHandler(const std::string &libName)
{
    return std::make_unique<LibHandler>("./lib/arcade_" + libName + ".so");
}

void Arcade::Core::Core::nextLib(LibType libType)
{
    const std::vector<std::string> &it2 = (libType == LibType::GAME) ? _gamesNames : _graphicLibsNames;
    std::string &currentLib = (libType == LibType::GAME) ? _currentGame : _currentGraphicLib;

    auto it = std::find(it2.begin(), it2.end(), currentLib);
    ++it;
    if (it == it2.end()) {
        ++it;
    }
    currentLib = *it;
}

void Arcade::Core::Core::changeLib(LibType libType)
{
    if (libType == LibType::GAME) {
        if (_currentGame.empty() && _gamesNames.size() > 0) {
            _currentGame = _gamesNames.front();
        } else {
            nextLib(libType);
        }
    } else {
        if (_graphicLibsNames.empty()) {
            throw std::invalid_argument("No shared graphic lib in lib/ folder");
        } else if (_currentGraphicLib.empty()) {
            _currentGraphicLib = _graphicLibsNames.front();
        } else {
            nextLib(libType);
        }
    }
}
