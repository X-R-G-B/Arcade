/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** GameScene
*/

#pragma once

#include "AScene.hpp"

#define NIBBLER_PADDING_WINDOW_X 576
#define NIBBLER_PADDING_WINDOW_Y 156
#define APPLE_SPRITE_COMP_PATH "assets/Nibbler/apple.png"

namespace Nibbler {
    namespace Scene {
        class GameScene : public Arcade::Game::AScene {
            public:
                GameScene();

                bool init() final;
                void close() final;
            protected:
                void createNibbler();
                void addNibblerHeadSprite(Arcade::ECS::IEntity &head);
                void createApple();
                void addNibblerMap();
            private:
                void addNibblerWallSquare(Arcade::ECS::IEntity &nibblerWalls, const Arcade::Vector3f &src_pos, int id);
                void addNibblerWall(Arcade::ECS::IEntity &nibblerWalls, const Arcade::Vector3f &pos, int id);
                void addNibblerParcel(Arcade::ECS::IEntity &nibblerMap, const Arcade::Vector3f &pos, int id);
                bool checkWallCollision(Arcade::ECS::IEntity &nibblerWalls, const  Arcade::Vector3f &pos);
                bool checkParcelCollision(Arcade::ECS::IEntity &nibblerMap, const  Arcade::Vector3f &pos);
        };
    }
}
