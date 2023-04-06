/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Events
*/

#pragma once

#include "ISystem.hpp"
// found at https://stackoverflow.com/questions/43923546/proper-way-of-catching-controlkey-in-ncurses
#define CTRL(x) ((x) & 0x1f)

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
