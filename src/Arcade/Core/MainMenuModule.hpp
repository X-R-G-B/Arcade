/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MainMenuModule
*/

#pragma once

#include <iostream>
#include "IGameModule.hpp"
#include "MainMenuScene.hpp"
#include "SystemManager.hpp"

namespace Arcade {
    namespace Core {
        class MainMenuModule : public Arcade::Game::IGameModule {
            public:
                MainMenuModule(
                    const std::vector<std::pair<std::string, std::string>> &gameLibs,
                    const std::vector<std::pair<std::string, std::string>> &graphicLibs
                    );
                ~MainMenuModule();

                void update(double deltaTime, Arcade::ECS::IEventManager &eventManager) final;
                Arcade::ECS::IEntityManager &getCurrentEntityManager() final;
            protected:
            private:
                std::unique_ptr<Arcade::Core::MainMenuScene> _mainMenu;
                std::unique_ptr<Arcade::ECS::SystemManager> _systemManager;
        };
    }
}
