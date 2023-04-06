/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AutoTurnSystem
*/

#pragma once

#include "ISystem.hpp"
#include "Direction.hpp"

namespace Nibbler {
    namespace System {
        class AutoTurnSystem : public Arcade::ECS::ISystem {
            public:
                void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentEntityManager) final;

                static Arcade::Vector2f toNextCase(const Arcade::Vector3f &pos, const Nibbler::Direction &direction);
            private:
                static bool isAbleToMove(const Arcade::Vector2f &pos, const std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &walls);
        };
    }
}
