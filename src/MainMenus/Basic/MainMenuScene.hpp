/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MainMenuScene
*/

#pragma once

#include "AScene.hpp"
#include "IMainMenuModule.hpp"

namespace BasicMenu {
    class MainMenuScene : public Arcade::Game::AScene {
        public:
            MainMenuScene(Arcade::MainMenu::Context *context);
            ~MainMenuScene() = default;

            bool init() final;
            void close() final;
        protected:
        private:
            Arcade::MainMenu::Context *_context;
    };
}
