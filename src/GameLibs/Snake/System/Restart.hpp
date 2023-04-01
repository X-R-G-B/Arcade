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
                Restart(Arcade::Game::IScene &scene)
                void run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentEntityManager) final;
            private:
                Arcade::Game::IScene &_scene;
        }
    }
}
