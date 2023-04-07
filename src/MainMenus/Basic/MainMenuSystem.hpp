/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MainMenuSystem
*/

#pragma once

#include "IMainMenuModule.hpp"
#include "ISystem.hpp"
#include "SaveScore.hpp"

namespace BasicMenu {
    class MainMenuSystem : public Arcade::ECS::ISystem {
        public:
            MainMenuSystem(Arcade::MainMenu::Context *context);
            ~MainMenuSystem() = default;

            void run(double deltaTime,
            Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &currentEntityManager) final;
        private:
            Arcade::MainMenu::Context *_context;
            bool _initialized = false;
            SaveScore::SaveScore _saveScore;
    };
}
