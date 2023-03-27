/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml Window
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "ISystem.hpp"

namespace Arcade {
    namespace Sfml {
        class Window : public ECS::ISystem {
            public:
                Window();
                void run(float delta,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &entityManager) final;
            private:
                sf::Window _win;
        };
    }
}
