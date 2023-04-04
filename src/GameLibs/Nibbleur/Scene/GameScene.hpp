/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** GameScene
*/

#pragma once

#include "AScene.hpp"

#define NBR_OF_PARCELS_IN_LINE 6
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
                void addNibblerWallSquare(Arcade::ECS::IEntityManager &entityManager, const Arcade::Vector3f &src_pos);
                void addNibblerWall(Arcade::ECS::IEntityManager &entityManager, const Arcade::Vector3f &pos, int nbrOfParcels);
                void addNibblerParcel(Arcade::ECS::IEntityManager &entityManager, const Arcade::Vector3f &pos, int nbrOfParcels);
        };
    }
}
