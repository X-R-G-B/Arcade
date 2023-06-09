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

namespace Snake {
    class SnakeGameModule : public Arcade::Game::IGameModule {
        public:
            SnakeGameModule();
            ~SnakeGameModule() = default;

            void update(double deltaTime, Arcade::ECS::IEventManager &eventManager) final;

            Arcade::ECS::IEntityManager &getCurrentEntityManager() final;

        private:
            Arcade::ECS::SystemManager _systemManager;
            std::vector<std::unique_ptr<Arcade::Game::IScene>> _scenes;
    };
}
