/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MainMenuModule
*/

#pragma once

#include "IGameModule.hpp"
#include "IMainMenuModule.hpp"
#include "MainMenuScene.hpp"
#include "SystemManager.hpp"

namespace BasicMenu {
    class MainMenuModule : public Arcade::MainMenu::IMainMenuModule {
        public:
            MainMenuModule(Arcade::MainMenu::Context *context);
            ~MainMenuModule();

            void update(double deltaTime, Arcade::ECS::IEventManager &eventManager,
            Arcade::MainMenu::Context *context) final;
            Arcade::ECS::IEntityManager &getCurrentEntityManager() final;
        protected:
        private:
            MainMenuScene _scene;
            Arcade::ECS::SystemManager _systemManager;
            Arcade::MainMenu::Context *_context;
    };
}
