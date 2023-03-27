/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MainMenuScene
*/

#pragma once

#include <iostream>
#include "AScene.hpp"

namespace Arcade {
    namespace Core {
        class MainMenuScene : public Arcade::Game::AScene {
            public:
                MainMenuScene(std::unique_ptr<Arcade::ECS::IEntityManager> enitityManager);

                bool init() final;
                void close() final;
            protected:
            private:
        };
    }
}
