/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** DisplayModule header
*/

#pragma once

#include "IDisplayModule.hpp"
#include "Module.hpp"
#include "ISystemManager.hpp"
#include "ComponentManager.hpp"

namespace Arcade {
    namespace Core {
        class DisplayModule : public IDisplayModule, public Module, public ECS::ComponentManager {
            public:
                DisplayModule(std::vector<std::string> libsNames);
                std::shared_ptr<ECS::ISystemManager> getSystemManager();
                void changeGraphicLib(
                const std::string &libGraphicName) final;
                void changeGraphicLib() final;
                Arcade::Vector2f &getWindowSize() final;
                void setWindowSize(const Arcade::Vector2f &newSize) final;
            private:
                void loadGraphicLib(const std::string &gameName);
                std::shared_ptr<Arcade::ECS::ISystemManager> _systemManager;
                Arcade::Vector2f _windowSize;
        };
    } // namespace Core
} // namespace Arcade
