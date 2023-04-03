/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** GameScene
*/

#pragma once

#include "AScene.hpp"

namespace Snake {
    namespace Scene {
        class GameScene : public Arcade::Game::AScene {
            public:
                GameScene();

                bool init() final;
                void close() final;
            protected:
            private:
        };
    }
}
