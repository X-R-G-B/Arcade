/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Ncurses
*/

#pragma once

#include <map>
#include "IDisplayModule.hpp"
#include "SystemManager.hpp"
#include "EntityManager.hpp"

namespace Ncurses {
    class DisplayModule : public Arcade::Graph::IDisplayModule {
        public:
            DisplayModule();
            ~DisplayModule();

            void update(double delta,
            Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &entityManager) final;

            static int getXFromX1920(int x);
            static int getYFromY1080(int y);
        private:
            double _frames;
            Arcade::ECS::SystemManager _systems;
            std::map<std::string, short> _colorsUsed;
            Arcade::ECS::EntityManager _entityManager;
    };
}
