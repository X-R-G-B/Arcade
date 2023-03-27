/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Core header
*/

#pragma once

#include <utility>
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
                std::vector<std::pair<std::string, std::string>> _gamesNames;
                std::vector<std::pair<std::string, std::string>> _graphicLibsNames;
                LibHandler<Graph::IDisplayModule> _graphLibHandler;
                LibHandler<Game::IGameModule> _gameLibHandler;

                void getSharedLibsNames();
                void addNameToList(const std::string &path);
                void checkChangeLib(ECS::IEventManager &eventManager);
                void nextLib(LibType libType);
        };
    }
}
