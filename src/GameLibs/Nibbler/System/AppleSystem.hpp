/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AppleSystem
*/

#pragma once

#include "ISystem.hpp"

namespace Nibbler {
    namespace System {
        class AppleSystem : public Arcade::ECS::ISystem {
            public:
                AppleSystem();

                void run(double deltaTime,
                    Arcade::ECS::IEventManager &eventManager,
                    Arcade::ECS::IEntityManager &entityManager) final;
            private:
                void modifyApplePos(Arcade::ECS::IEventManager &eventManager,
                    Arcade::ECS::IEntityManager &currentEntityManager);
                std::vector<Arcade::Vector3f> _positions;
        };
    }
}
