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
#include "Api.hpp"
#include "Core.hpp"
#include "EntityManager.hpp"
#include "Exceptions.hpp"

Arcade::Core::Core::Core(const std::string &path)
{
    getSharedLibsNames();
    if (path.empty()) {
        nextLib(LibType::GRAPH);
    } else {
        loadGraphicLibFromPath(path);
    }
    _mainMenu = std::make_unique<Arcade::Core::MainMenuModule>(this->_gamesNames, this->_graphicLibsNames);
}

void Arcade::Core::Core::addNameToList(const std::string &path)
{
    std::string name;
    LibType type;
    std::string path2 = path;

    std::cerr << "Trying to load: '" << path2 << "' ..." << std::endl;
    try {
        name = LibHandler<Graph::IDisplayModule>::getLibName(path2);
        std::cerr << "Name: '" << name << "'" << std::endl;
        type = LibHandler<Graph::IDisplayModule>::getLibType(path2);
        std::cerr << "Type: '" << type << "'" << std::endl;
    } catch (std::exception &e) {
        std::cerr << "File is not a shared library: " << path2 << std::endl;
        std::cerr << e.what() << std::endl;
        return;
    }
    std::cerr << "File is a shared library: " << path2 << std::endl << std::endl;
    if (type == LibType::GAME) {
        _gamesNames.push_back(std::make_pair(name, path2));
    } else {
        _graphicLibsNames.push_back(std::make_pair(name, path2));
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

Arcade::ECS::IEntityManager &Arcade::Core::Core::updater(std::chrono::duration<double> delta,
                    Arcade::ECS::EventManager &eventManager)
{
    if (_gameLibHandler.getModule() != nullptr) {
        _gameLibHandler.getModule()->update(delta.count(), eventManager);
        return (_gameLibHandler.getModule()->getCurrentEntityManager());
    } else {
        _mainMenu->update(delta.count(), eventManager);
        return (_mainMenu->getCurrentEntityManager());
    }
}

void Arcade::Core::Core::update()
{
    Arcade::ECS::EventManager eventManager;
    std::chrono::_V2::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::chrono::duration<double> delta(0);

    while (eventManager.isEventTriggered("QUIT").first == false) {
        delta = start - std::chrono::steady_clock::now();
        start = std::chrono::steady_clock::now();

        checkChangeLib(eventManager);
        eventManager.clearEvents();
        auto &entityManager = this->updater(delta, eventManager);
        if (_graphLibHandler.getModule() != nullptr) {
            _graphLibHandler.getModule()->update(
                delta.count(),
                eventManager,
                entityManager);
        }
    }
}

void Arcade::Core::Core::checkChangeLib(ECS::IEventManager &eventManager)
{
    if (eventManager.isEventTriggered("CHANGE_GAME").first == true) {
        nextLib(LibType::GAME);
    } else if (eventManager.isEventTriggered("CHANGE_GRAPH").first == true) {
        nextLib(LibType::GRAPH);
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
        } else {
            _gameLibHandler.loadLib(path);
        }
    } else {
        if (path.empty()) {
            _graphLibHandler.reset();
        } else {
            _graphLibHandler.loadLib(path);
        }
    }
}
