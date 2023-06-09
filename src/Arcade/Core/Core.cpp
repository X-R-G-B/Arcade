/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Core code
*/

#include <iostream>
#include <functional>
#include <filesystem>
#include <optional>
#include <ostream>
#include <stdexcept>
#include <utility>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "Core.hpp"
#include "EntityManager.hpp"
#include "Exceptions.hpp"

Arcade::Core::Core::Core(const std::string &path)
{
    getSharedLibsNames();
    if (_mainMenuLibHandler.getModule() == nullptr) {
        throw std::runtime_error("No availible main menu, exiting...");
    }
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
    std::string path2 = path;

    try {
        name = LibHandler<Graph::IDisplayModule>::getLibName(path2);
        type = LibHandler<Graph::IDisplayModule>::getLibType(path2);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "File is not a compliant shared library: " << path2 << std::endl << std::endl;
        return;
    }
    if (type == LibType::GAME) {
        _gamesNames.push_back(std::make_pair(name, path2));
        _context.gameLibraries.push_back(name);
    } else if (type == LibType::GRAPH) {
        _graphicLibsNames.push_back(std::make_pair(name, path2));
        _context.graphicalLibraries.push_back(name);
    } else {
        _mainMenuLibHandler.loadLib(path2, &_context);
        std::cerr << "File is main menu, loaded as default (overriding older main menu selected)" << std::endl;
    }
}

void Arcade::Core::Core::getSharedLibsNames()
{
    bool is_lib = false;
    std::string path;

    for (const auto &entry : std::filesystem::directory_iterator(_libFolderPath)) {
        path = std::string(entry.path());
        is_lib = path.ends_with(".so");
        if (is_lib == false) {
            std::cerr << "File is not a shared library: " << path << std::endl;
        } else {
            addNameToList(path);
        }
    }
    for (const auto &entry : std::filesystem::directory_iterator(_libFolderMainMenuPath)) {
        path = std::string(entry.path());
        is_lib = path.ends_with(".so");
        if (is_lib == false) {
            std::cerr << "File is not a shared library: " << path << std::endl;
        } else {
            addNameToList(path);
        }
    }
    if (_gamesNames.empty() && _graphicLibsNames.empty()) {
        throw ArcadeExceptions("Invalid argument => Empty lib folder");
    }
}

void Arcade::Core::Core::loadGraphicLibFromPath(const std::string &path)
{
    std::size_t start = path.find("arcade_");
    std::size_t end = path.find(".so");

    if (start == std::string::npos || end == std::string::npos) {
        throw ArcadeExceptions("Invalid argument => Invalid path");
    }
    _graphLibHandler.loadLib(path);
}

void Arcade::Core::Core::updater(std::chrono::duration<double> delta,
                    Arcade::ECS::EventManager &eventManager)
{
    if (_graphLibHandler.getModule() == nullptr) {
        return;
    }
    if (_gameLibHandler.getModule() != nullptr) {
        _graphLibHandler.getModule()->update(
            delta.count() * 100,
            eventManager,
            _gameLibHandler.getModule()->getCurrentEntityManager());
        _gameLibHandler.getModule()->update(delta.count() * 100, eventManager);
    } else {
        _graphLibHandler.getModule()->update(
            delta.count() * 100,
            eventManager,
            _mainMenuLibHandler.getModule()->getCurrentEntityManager());
        _mainMenuLibHandler.getModule()->update(delta.count() * 100, eventManager, &_context);
    }
}

void Arcade::Core::Core::update()
{
    Arcade::ECS::EventManager eventManager;
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> delta(0);

    while (eventManager.isEventTriggered("QUIT").first == false) {
        eventManager.clearEvents();
        delta = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start);
        start = std::chrono::high_resolution_clock::now();
        this->updater(delta, eventManager);
        checkChangeLib(eventManager);
    }
}

void Arcade::Core::Core::checkChangeLib(ECS::IEventManager &eventManager)
{
    if (eventManager.isEventTriggered("CHANGE_GAME").first == true) {
        nextLib(LibType::GAME);
    } else if (eventManager.isEventTriggered("CHANGE_GRAPH").first == true) {
        nextLib(LibType::GRAPH);
    } else if (eventManager.isEventTriggered("GAME_END").first) {
        _gameLibHandler.reset();
    }
}

void Arcade::Core::Core::nextLib(LibType libType)
{
    const auto &it2 = (libType == LibType::GAME) ? _gamesNames : _graphicLibsNames;
    const std::string &currentLib = (libType == LibType::GAME) ? _gameLibHandler.getName() : _graphLibHandler.getName();
    std::string path;

    auto it = it2.begin();
    for (; it != it2.end(); ++it) {
        if ((*it).first == currentLib) {
            ++it;
            break;
        }
    }
    if (it == it2.end()) {
        it = it2.begin();
    }
    if (it == it2.end()) {
        path = "";
    } else {
        path = (*it).second;
    }
    if (libType == LibType::GAME) {
        if (path.empty()) {
            _gameLibHandler.reset();
            _context.currentGameLibrary = "";
        } else {
            _gameLibHandler.loadLib(path);
            _context.currentGameLibrary = _gameLibHandler.getName();
        }
    } else {
        if (path.empty()) {
            _graphLibHandler.reset();
            _context.currentGraphicalLibrary = "";
        } else {
            _graphLibHandler.loadLib(path);
            _context.currentGraphicalLibrary = _graphLibHandler.getName();
        }
    }
}
