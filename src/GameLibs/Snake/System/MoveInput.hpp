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
        class MoveInput : public Arcade::ECS::ISystem {
            public:
                MoveInput(const Direction &snakeDirection);
                ~MoveInput() = default;

                void run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentEntityManager) final;

            private:
                const Direction &_snakeDirection;
        };
    }
}
