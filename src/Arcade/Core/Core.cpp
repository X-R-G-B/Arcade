/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Core Abstract
*/

#include <iostream>
#include <functional>
#include <filesystem>
#include <stdexcept>
#include "Core.hpp"
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

Arcade::Core::Core::Core()
{
    getSharedLibsNames();
    std::cout << _gamesNames.front() << std::endl;
    std::cout << _graphicLibsNames.front() << std::endl;
    //TODO call GameModule constructor
    //TODO call DisplayModule constructor
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

    for (const auto &entry : std::filesystem::directory_iterator(libFolderPath)) {
        path = std::string(entry.path());
        pos = path.find(".so");
        if (pos == std::string::npos || pos + 3 != path.length()) {
            throw std::invalid_argument("File is not a shared library: " + path);
        }
        LibHandler.loadLib(path);
        type = LibHandler.loadFunction<LibType>("getType");
        addNameToList(type, LibHandler);
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
    //_displayModule.changeGraphicLib(path.substr(start + 7, end))
    //TODO uncomment when DisplayModule attribute is emplemented
}
