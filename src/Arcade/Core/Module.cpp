/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** module class
*/

#include <algorithm>
#include "Module.hpp"

Arcade::Core::Module::Module(std::vector<std::string> libsNames) : _libsNames(libsNames)
{
}

std::unique_ptr<LibHandler> Arcade::Core::Module::getLibHandler(const std::string &libName)
{
    return std::make_unique<LibHandler>("./lib/arcade_" + libName + ".so");
}

void Arcade::Core::Module::nextLib()
{
    auto it = find(_libsNames.begin(), _libsNames.end(), _currentLib);

    ++it;
    if (it == _libsNames.end()) {
        _currentLib = _libsNames.front();
        return;
    }
    _currentLib = *it;
}

void Arcade::Core::Module::changelib()
{
    if (_currentLib.empty() && _libsNames.size() > 0) {
        _currentLib = _libsNames.front();
    } else {
        nextLib();
    }
}
