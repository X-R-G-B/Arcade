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
#include "ACore.hpp"
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

Arcade::Core::ACore::ACore()
{
    getSharedLibsNames();
    std::cout << _gamesNames.front() << std::endl;
    std::cout << _graphicLibsNames.front() << std::endl;
    //TODO call GameModule constructor
    //TODO call DisplayModule constructor
}

void Arcade::Core::ACore::addNameToList(LibType type, libHandler &libHandler)
{
    std::function<std::string()> _getName;

    _getName = libHandler.loadFunction<std::string()>("getName");
    if (type == LibType::GAME) {
        _gamesNames.push_back(_getName());
    } else {
        _graphicLibsNames.push_back(_getName());
    }
}

void Arcade::Core::ACore::getSharedLibsNames()
{
    std::size_t pos;
    libHandler libHandler;
    std::function<LibType()> _getType;

    for (const auto &entry : std::filesystem::directory_iterator(libFolderPath)) {
        pos = entry.path().find(".so");
        if (pos == std::string::npos || pos + 3 != entry.path().length()) {
            throw std::invalid_argument("File is not a shared library: " + entry.path());
        }
        libHandler.loadLib(entry.path());
        _getType = libHandler.loadFunction<LibType()>("getType");
        addNameToList(_getType(), libHandler);
    }
}

void Arcade::Core::ACore::loadGraphicLibFromPath(const std::string &path)
{
    libHandler libHandler;
    std::size_t start = path.find("arcade_");
    std::size_t end = path.find(".so");
    std::function<LibType()> _getType;

    if (start == std::string::npos || end == std::string::npos) {
        throw std::invalid_argument("Invalid path");
    }
    libHandler.loadLib(path);
    _getType = libHandler.loadFunction<LibType()>("getType");
    if (_getType() == LibType::GAME) {
        throw std::invalid_argument("Wrong shared library type, you must load a graphic lib");
    }
    //_displayModule.changeGraphicLib(path.substr(start + 7, end))
    //TODO uncomment when DisplayModule attribute is emplemented
}
