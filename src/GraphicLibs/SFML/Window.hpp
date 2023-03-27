/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml Window
*/

#pragma once

#include <Sfml/Graphics/Window.hpp>
#include "ISystem.hpp"

namespace Arcade {
    namespace Sfml {
        class Window : public ISystem {
            public:
                Window();
                void update(float delta,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &entityManager) final;
            private:
                sf::Window win;
        }
    }
}
