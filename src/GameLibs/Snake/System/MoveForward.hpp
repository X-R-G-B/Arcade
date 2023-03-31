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
        class MoveForward : public Arcade::ECS::ISystem {
            public:
                MoveForward();
                ~MoveForward() = default;

                void run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentEntityManager) final;
        };
    }
}
