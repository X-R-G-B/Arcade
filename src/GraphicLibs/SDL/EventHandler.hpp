/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EventHandler
*/

#pragma once

#include "ISystem.hpp"

namespace Arcade {
    namespace SDL {
        class EventHandler : public Arcade::ECS::ISystem {
            public:
                EventHandler() = default;
                ~EventHandler() = default;

                void run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentScene) final;
            protected:
            private:
        };
    }
}
