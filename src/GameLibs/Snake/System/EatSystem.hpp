/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EatSystem
*/

#pragma once

#include "ISystem.hpp"

namespace Snake {
    namespace System {
        class EatSystem : Arcade::ECS::ISystem {
            public:
                void run(float deltaTime,
                    Arcade::ECS::IEventManager &eventManager,
                    Arcade::ECS::IEntityManager &currentEntityManager) final;
        };
    }
}
