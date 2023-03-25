/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Core header
*/

#pragma once

#include <vector>
#include "ICore.hpp"
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "Api.hpp"
#include "LibHandler.hpp"

namespace Arcade {
    namespace Core {
        class Core : public ICore {
            public:
                Core(const std::string &path);
                void update() final;

                void loadGraphicLibFromPath(const std::string &path);
            private:
                const std::string libFolderPath = "./lib";
                std::vector<std::string> _gamesNames;
                std::vector<std::string> _graphicLibsNames;
                std::string _currentGame;
                std::string _currentGraphicLib;
                std::unique_ptr<IGameModule> _gameModule;
                std::unique_ptr<IDisplayModule> _displayModule;

                void getSharedLibsNames();
                void addNameToList(LibType type, LibHandler &LibHandler);
                std::unique_ptr<LibHandler> getLibHandler(const std::string &libName);
                void checkChangeLib(ECS::IEventManager &eventManager);
                void nextLib(LibType libType);
                void changeLib(LibType libType);
        };
    }
}
