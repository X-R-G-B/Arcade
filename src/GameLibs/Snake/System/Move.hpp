/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake Move System
*/

#pragma once

#include "ISystem.hpp"
#include "Direction.hpp"

namespace Snake {
    namespace System {
        class Move : public Arcade::ECS::ISystem {
            public:
                Move(const Direction &snakeDirection);
                ~Move() = default;

                void run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentEntityManager) final;

            private:
                const Direction &_snakeDirection;
        };
    }
}
