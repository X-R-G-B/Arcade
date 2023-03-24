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
                Core();
                void loadGraphicLibFromPath(const std::string &path);
                void update();

                const std::string libFolderPath = "./lib";
            private:
                std::vector<std::string> _gamesNames;
                std::vector<std::string> _graphicLibsNames;
                std::unique_ptr<IGameModule> _gameModule;
                //TODO DisplayModule concrete class

                void getSharedLibsNames();
                void addNameToList(LibType type, LibHandler &LibHandler);
        };
    }
}
