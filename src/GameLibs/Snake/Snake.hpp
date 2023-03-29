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
#include <vector>

namespace Snake {
    class SnakeScene : public Arcade::Game::AScene {
        public:
            SnakeScene();
            ~SnakeScene() = default;

    };

    class SnakeGameModule : public Arcade::Game::IGameModule {
        public:
            SnakeGameModule();
            ~SnakeGameModule() = default;

            void update(float deltaTime, Arcade::ECS::IEventManager &eventManager) final;

            Arcade::ECS::IEntityManager &getCurrentEntityManager() final;

        private:
            Direction _snakeDirection = Direction::RIGHT;
            Arcade::ECS::SystemManager _systemManager;
            std::vector<Arcade::Game::IScene> _scenes;
    };
}
