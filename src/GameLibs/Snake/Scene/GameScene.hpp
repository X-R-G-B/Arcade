/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** GameScene
*/

#pragma once

#include "AScene.hpp"

#define NBR_OF_PARCELS_IN_LINE 6
#define SNAKE_PADDING_WINDOW_X 576
#define SNAKE_PADDING_WINDOW_Y 156

namespace Snake {
    namespace Scene {
        class GameScene : public Arcade::Game::AScene {
            public:
                GameScene();

                bool init() final;
                void close() final;
            protected:
                void createSnake();
                void addSnakeHeadSprite(Arcade::ECS::IEntity &head);
                void createApple();
                void addSnakeMap();
            private:
        };
    }
}
