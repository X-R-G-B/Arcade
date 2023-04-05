/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MainMenuSystem
*/

#pragma once

#include "IMainMenuModule.hpp"
#include "ISystem.hpp"

namespace BasicMenu {
    class MainMenuSystem : public Arcade::ECS::ISystem {
        public:
            MainMenuSystem(Arcade::MainMenu::Context *context);
            ~MainMenuSystem() = default;

            virtual void run(double deltaTime,
            Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &currentEntityManager) = 0;
        private:
            Arcade::MainMenu::Context *_context;
            bool _initialized = false;
    };
}
