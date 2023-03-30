/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AppleSystem
*/

#pragma once

#include "ISystem.hpp"

namespace Snake {
    namespace System {
        class AppleSystem : public Arcade::ECS::ISystem {
            public:
                AppleSystem();
                ~AppleSystem();

                void run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &entityManager) final;
            protected:
            private:
                std::vector<Arcade::Vector3f> _positions;
        };
    }
}
