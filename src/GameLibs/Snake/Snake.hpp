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
#include <memory>
#include <vector>

namespace Arcade {
    namespace ECS {
        enum class CompType {
            TEXT = 0,
            SPRITE = 1,
            MUSIC = 2,
            DIRECTION = 201
        };
    }
}

namespace Snake {
    class SnakeGameModule : public Arcade::Game::IGameModule {
        public:
            SnakeGameModule();
            ~SnakeGameModule() = default;

            void update(float deltaTime, Arcade::ECS::IEventManager &eventManager) final;

            Arcade::ECS::IEntityManager &getCurrentEntityManager() final;

        private:
            Direction _snakeDirection = Direction::RIGHT;
            Arcade::ECS::SystemManager _systemManager;
            std::vector<std::unique_ptr<Arcade::Game::IScene>> _scenes;
    };
}
