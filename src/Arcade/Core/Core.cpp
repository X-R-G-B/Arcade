/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Core code
*/

#include <iostream>
#include <functional>
#include <filesystem>
#include <ostream>
#include <stdexcept>
#include <chrono>
#include "EventManager.hpp"
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "Api.hpp"
#include "Core.hpp"

Arcade::Core::Core::Core(const std::string &path) : _gameModule(nullptr), _displayModule(nullptr)
{
    getSharedLibsNames();
    if (path.empty()) {
        nextLib(LibType::GRAPH);
    } else {
        loadGraphicLibFromPath(path);
    }
}

void Arcade::Core::Core::addNameToList(const std::string &path)
{
    std::string name;
    LibType type;
 
    std::cout << "Loading " << path << std::endl;
    name = LibHandler<Graph::IDisplayModule>::getLibName(path);
    std::cout << "Loading1 " << path << std::endl;
    type = LibHandler<Graph::IDisplayModule>::getLibType(path);
    std::cout << "Loading2 " << path << std::endl;
    if (type == LibType::GAME) {
        _gamesNames.push_back(name);
    } else {
        _graphicLibsNames.push_back(name);
    }
}

void Arcade::Core::Core::getSharedLibsNames()
{
    std::size_t pos;
    std::string path;
    bool empty = true;

    for (const auto &entry : std::filesystem::directory_iterator(_libFolderPath)) {
        if (empty == true) {
            empty = false;
        }
        path = std::string(entry.path());
        pos = path.find(".so");
        if (pos == std::string::npos || pos + 3 != path.length()) {
            std::cerr << "File is not a shared library: " << path << std::endl;
        } else {
            addNameToList(path);
        }
    }
    if (empty) {
        throw std::invalid_argument("Empty lib folder");
    }
}

void Arcade::Core::Core::loadGraphicLibFromPath(const std::string &path)
{
    std::size_t start = path.find("arcade_");
    std::size_t end = path.find(".so");

    if (start == std::string::npos || end == std::string::npos) {
        throw std::invalid_argument("Invalid path");
    }
    std::cout << "Loading graphic lib: " << path << std::endl;
    _graphLibHandler.loadLib(path);
    std::cout << "Loading graphic lib1: " << path << std::endl;
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
        nextLib(LibType::GAME);
    } else if (eventManager.isEventTriggered("CHANGE_GRAPH").first) {
        nextLib(LibType::GRAPH);
    }
}

void Arcade::Core::Core::nextLib(LibType libType)
{
    const std::vector<std::string> &it2 = (libType == LibType::GAME) ? _gamesNames : _graphicLibsNames;
    const std::string &currentLib = (libType == LibType::GAME) ? _gameLibHandler.getName() : _graphLibHandler.getName();
    std::string path;

    auto it = std::find(it2.begin(), it2.end(), currentLib);
    ++it;
    if (it == it2.end()) {
        ++it;
    }
    path = "./lib/arcade_" + *it + ".so";
    if (libType == LibType::GAME) {
        _gameLibHandler.loadLib(path);
    } else {
        _graphLibHandler.loadLib(path);
    }
}
