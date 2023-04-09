/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** GameScene
*/

#pragma once

#include "AScene.hpp"

namespace Nibbler {
    namespace Scene {
        class GameScene : public Arcade::Game::AScene {
            public:
                GameScene();

                bool init() final;
                void close() final;
                static void addSnakeHeadSprite(Arcade::ECS::IEntity &head);
            protected:
                void createSnake();
                void createApple();
                void addNibblerMap();
                void addScore();
            private:
                void addNibblerWallSquare(Arcade::ECS::IEntity &nibblerWalls, const Arcade::Vector3f &src_pos, int id);
                void addNibblerWall(Arcade::ECS::IEntity &nibblerWalls, const Arcade::Vector3f &pos, int id);
                void addNibblerParcel(Arcade::ECS::IEntity &nibblerMap, const Arcade::Vector3f &pos, int id, Arcade::ECS::IEntity &nibblerWalls);
                bool checkWallCollision(Arcade::ECS::IEntity &nibblerWalls, const  Arcade::Vector3f &pos, std::vector<std::string> &idToIgnore);
                bool checkParcelCollision(Arcade::ECS::IEntity &nibblerMap, const  Arcade::Vector3f &pos);
                int generateRandomInt(int max);
        };
    }
}
