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
        Arcade::Vector2f toNextCase(const Arcade::Vector3f &pos, const Snake::Direction &direction);

        class MoveInput : public Arcade::ECS::ISystem {
            public:
                MoveInput();
                ~MoveInput() = default;

                void run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentEntityManager) final;
        };
    }
}
