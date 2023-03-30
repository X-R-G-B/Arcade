/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake header
*/

#include "IGameModule.hpp"
#include "Scene/GameScene.hpp"
#include "SystemManager.hpp"

namespace Snake {
    class Snake : public Arcade::Game::IGameModule {
        public:
            Snake();
            void update(float deltaTime, Arcade::ECS::IEventManager &eventManager) final;
            Arcade::ECS::IEntityManager &getCurrentEntityManager() final;
        private:
            Snake::Scene::GameScene _scene;
            Arcade::ECS::SystemManager _systemManager;
    };
}
