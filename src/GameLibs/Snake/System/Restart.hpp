/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EntryPoint
*/

#include "ISystem.hpp"
#include "IScene.hpp"

namespace Snake {
    namespace System {
        class Restart : public Arcade::ECS::ISystem {
            public:
                Restart(std::unique_ptr<Arcade::Game::IScene> &scene);
                void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentEntityManager) final;
            private:
                std::unique_ptr<Arcade::Game::IScene> &_scene;
        };
    }
}
