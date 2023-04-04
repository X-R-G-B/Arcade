/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EntryPoint
*/

#pragma once

#include "Direction.hpp"
#include "IGameModule.hpp"
#include "IScene.hpp"
#include "SystemManager.hpp"
#include "AScene.hpp"
#include "Sprite.hpp"

#define NBR_OF_PARCELS_IN_LINE 6
#define SNAKE_PADDING_WINDOW_X 576
#define SNAKE_PADDING_WINDOW_Y 156

namespace Snake {
    class SnakeGameModule : public Arcade::Game::IGameModule {
        public:
            SnakeGameModule();
            ~SnakeGameModule() = default;

            void update(double deltaTime, Arcade::ECS::IEventManager &eventManager) final;

            Arcade::ECS::IEntityManager &getCurrentEntityManager() final;

        private:
            void createSnake();
            void addSnakeHeadSprite(Arcade::ECS::IEntity &head);
            Direction _snakeDirection = Direction::RIGHT;
            Arcade::ECS::SystemManager _systemManager;
            std::vector<std::unique_ptr<Arcade::Game::IScene>> _scenes;
            void addSnakeMap();
    };
}
