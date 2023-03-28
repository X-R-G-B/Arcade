/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml
*/

#pragma once

#include <SFML/Window.hpp>
#include "IDisplayModule.hpp"
#include "SystemManager.hpp"

namespace Arcade {

    namespace Sfml {

        class DisplayModule : public Graph::IDisplayModule {
            public:
                DisplayModule();
                void update(float delta,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &entityManager) final;
            private:
                ECS::SystemManager _systems;
                sf::Window _win;
        };
    }
}
