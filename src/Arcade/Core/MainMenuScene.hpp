/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MainMenuScene
*/

#pragma once

#include "AScene.hpp"

namespace Arcade {
    namespace Core {
        class MainMenuScene : public Arcade::Game::AScene {
            public:
                MainMenuScene(
                    std::unique_ptr<Arcade::ECS::IEntityManager> enitityManager,
                    const std::vector<std::pair<std::string, std::string>> &gameLibs,
                    const std::vector<std::pair<std::string, std::string>> &graphicLibs
                );
                ~MainMenuScene() = default;

                bool init() final;
                void close() final;
            protected:
            private:
                const std::vector<std::pair<std::string, std::string>> &_gameLibs;
                const std::vector<std::pair<std::string, std::string>> &_graphicLibs;
        };
    }
}
