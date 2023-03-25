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
#include "Core.hpp"
#include "IEventManager.hpp"
#include "IDisplayModule.hpp"

Arcade::Core::Core::Core()
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
    changelib(LibType::GRAPH);
}

void Arcade::Core::Core::update()
{
    std::unique_ptr<Arcade::ECS::IEventManager> eventManager;// = std::make_unique<Arcade::ECS::EventManager>(); TODO need EventManager
    std::chrono::_V2::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::chrono::duration<double> delta(0);
    //std::unique_ptr<IScene> mainMenu = getMainMenu() TODO need main menu

    //for (eventManager->isEventTriggered("QUIT").first == false) { TODO need EventManager
        delta = start - std::chrono::steady_clock::now();
        //if (_gameModule->isGameLoaded() == false) { TODO need GameModule
        //  mainMenu->getSystemManager->update(delta.count(), eventManager, _displayModule, _gameModule) // TODO need main menu
        //}
        //else {
            //_gameModule->getSceneManager()->getCurrentScene()->getSystemManager()->update(delta.count(), eventManager, _displayModule, _gameModule); TODO need All
        //}
        //_displayModule()->getSystemManager()->update(delta.count(), eventManager, _displayModule, _gameModule)
        start = std::chrono::steady_clock::now();
    //}
}

void Arcade::Core::Core::checkChangeLib(ECS::IEventManager &eventManager)
{
    if (eventManager.isEventTriggered("CHANGE_GAME").first) {
        changeLib(LibType::GAME);
        loadLib();
    } else if (eventManager.isEventTriggered("CHANGE_GRAPH").first) {
        changeLib(LibType::GRAPH);
        loadLib();
    }
}

void Arcade::Core::Core::loadLib(LibType type)
{
    std::unique_ptr<LibHandler> libHandler = getLibHandler(gameName);

    if (type == LibType::GAME) {
        _gameModule.reset();
        _gameModule = libHandler->loadMainFunction<std::shared_ptr<Arcade::Game::IGameModule>>("getGameModule", _sceneManager);
    } else {
        _displayModule.reset();
        _displayModule = libHandler->loadMainFunction<std::shared_ptr<Arcade::Game::IDisplayModule>>("getDisplayModule", _sceneManager);
    }
}

std::unique_ptr<LibHandler> Arcade::Core::Core::getLibHandler(const std::string &libName)
{
    return std::make_unique<LibHandler>("./lib/arcade_" + libName + ".so");
}

void Arcade::Core::Core::nextLib(LibType libType)
{
    auto it = find(_libsNames.begin(), _libsNames.end(), _currentLib);

    ++it;
    if (it == _libsNames.end()) {
        _currentLib = _libsNames.front();
        return;
    }
    _currentLib = *it;
}

void Arcade::Core::Core::changelib(LibType libType)
{
    if (libType == LibType::Game) {
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
