/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Core Abstract
*/

#include <functional>
#include <filesystem>
#include "ACore.hpp"
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

Arcade::Core::ACore::ACore()
{
    getSharedLibsNames();
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
            //TODO wrong file in lib/ folder exception
            throw std::exception;
        }
        libHandler.loadLib(entry.path());
        _getType = libHandler.loadFunction<LibType()>("getType");
        addNameToList(_getType(), libHandler);
    }
}

Arcade::Core::ACore::loadGraphicLibFromPath(const std::string &path)
{
    libHandler libHandler;
    std::size_t start = path.find("arcade_");
    std::size_t end = path.find(".so");
    std::function<LibType()> _getType;

    if (start == std::string::npos || end == std::string::npos) {
        //TODO wrong argument exception
        throw std::exception;
    }
    libHandler.loadLib(path);
    _getType = libHandler.loadFunction<LibType()>("getType");
    if (_getType() == LibType::GAME) {
        //TODO wrong argument exception
        throw std::exception;
    }
    _displayModule.changeGraphicLib(path.substr(start + 7, end))
}
