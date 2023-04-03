/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake Move System
*/

#pragma once

#include "ISystem.hpp"
#include "Forward.hpp"
#include "ISprite.hpp"
#include "Direction.hpp"

namespace Snake {
    namespace System {
        class MoveForward : public Arcade::ECS::ISystem {
            public:
                void run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentEntityManager) final;
            private:
                void moveForward(
                Snake::Component::Forward &curDir,
                Arcade::Graph::ISprite &sprite,
                float deltaTime);
        };
    }
}
