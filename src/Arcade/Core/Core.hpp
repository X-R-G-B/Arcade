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
                const std::string _libFolderPath = "./lib";
                std::vector<std::string> _gamesNames;
                std::vector<std::string> _graphicLibsNames;
                Arcade::Game::IGameModule *_gameModule;
                Arcade::Graph::IDisplayModule *_displayModule;
                LibHandler<Graph::IDisplayModule> _graphLibHandler;
                LibHandler<Game::IGameModule> _gameLibHandler;

                void getSharedLibsNames();
                void addNameToList(const std::string &path);
                void checkChangeLib(ECS::IEventManager &eventManager);
                void nextLib(LibType libType);
        };
    }
}
