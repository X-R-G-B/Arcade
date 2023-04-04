/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Ncurses
*/

#pragma once

#include "IDisplayModule.hpp"
#include "SystemManager.hpp"

namespace Ncurses {
    class DisplayModule : public Arcade::Graph::IDisplayModule {
        public:
            DisplayModule();
            ~DisplayModule();

            void update(float delta,
            Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &entityManager) final;
        private:
            double _frames;
            Arcade::ECS::SystemManager _systems;
    };
}
