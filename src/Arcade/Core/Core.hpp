/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Core header
*/

#pragma once

#include <vector>
#include "ICore.hpp"
#include "EventManager.hpp"
#include "Api.hpp"
#include "LibHandler.hpp"
#include "IGameModule.hpp"
#include "IDisplayModule.hpp"

namespace Arcade {
    namespace Core {
        class Core : public ICore {
            public:
                Core(const std::string &path);
                void update();

                const std::string libFolderPath = "./lib";
            private:
                std::vector<std::string> _gamesNames;
                std::vector<std::string> _graphicLibsNames;
                std::string _currentGame;
                std::string _currentGraphicLib;
                std::unique_ptr<IGameModule> _gameModule;
                std::unique_ptr<IDisplayModule> _displayModule;

                void getSharedLibsNames();
                void addNameToList(LibType type, LibHandler &LibHandler);
                void loadGraphicLibFromPath(const std::string &path);
                std::unique_ptr<LibHandler> getLibHandler(const std::string &libName);
                void nextLib();
                void changelib();
        };
    }
}
