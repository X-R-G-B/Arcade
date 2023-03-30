/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Collision
*/

#pragma once

#include "ISystem.hpp"

namespace Snake {
    namespace System {
        class Collision : Arcade::ECS::ISystem {
            public:
                Collision();

            void run(float deltaTime,
            Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &currentEntityManager);
            protected:
            private:
        };
    }
}
