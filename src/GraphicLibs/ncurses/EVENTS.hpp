/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Events
*/

#pragma once

#include "ISystem.hpp"

namespace Ncurses {
    namespace System {
        class EventsSystem : public Arcade::ECS::ISystem {
            public:
                void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &entityManager) final;
        };
    }
}
