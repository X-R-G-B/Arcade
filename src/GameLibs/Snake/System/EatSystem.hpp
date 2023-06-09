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
        class EatSystem : public Arcade::ECS::ISystem {
            public:
                EatSystem() = default;

                void run(double deltaTime,
                    Arcade::ECS::IEventManager &eventManager,
                    Arcade::ECS::IEntityManager &currentEntityManager) final;
            private:
                int _id = 0;
        };
    }
}
