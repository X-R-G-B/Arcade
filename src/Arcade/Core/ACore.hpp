/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Core Abstract
*/

#pragma once

#include <vector>
#include "ICore.hpp"
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "Api.hpp"
#include "libHandler.hpp"

namespace Arcade {
    namespace Core {
        class ACore : public ICore {
            public:
                ACore();
                loadGraphicLibFromPath(const std::string &path);

                const std::string libFolderPath = "./lib";
                const std::string libPathStart = "./lib/arcade_";
                const std::string libPathEnd = ".so";
            private:
                std::vector<std::string> _gamesNames;
                std::vector<std::string> _graphicLibsNames;
                //TODO GameModule concrete class
                //TODO DisplayModule concrete class

                void getSharedLibsNames();
                void addNameToList(LibType type, libHandler &libHandler);
        };
    }
}