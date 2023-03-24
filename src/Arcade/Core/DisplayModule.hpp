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
                void addComponent(std::shared_ptr<ECS::IComponent> component);
                void removeComponent(const std::string &componentId);
                std::optional<std::shared_ptr<ECS::IComponent>>
                getComponent(const std::string &componentId) const;
                const std::vector<std::shared_ptr<ECS::IComponent>> &
                getComponents(ECS::CompType type) const;
                Arcade::Vector2f &getWindowSize() final;
                void setWindowSize(const Arcade::Vector2f &newSize) final;
            private:
                void loadGraphicLib(const std::string &gameName);
                std::shared_ptr<Arcade::ECS::ISystemManager> _systemManager;
                Arcade::Vector2f _windowSize;
        };
    } // namespace Core
} // namespace Arcade
