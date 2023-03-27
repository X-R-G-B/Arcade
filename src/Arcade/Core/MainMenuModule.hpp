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

namespace Arcade {
    namespace Core {
        class MainMenuModule : public Arcade::Game::IGameModule {
            public:
                MainMenuModule();
                ~MainMenuModule();

                void update(float deltaTime, Arcade::ECS::IEventManager &eventManager) final;
                Arcade::ECS::IEntityManager &getCurrentEntityManager() final;
            protected:
            private:
                std::unique_ptr<Arcade::Core::MainMenuScene> _mainMenu;
        };
    }
}