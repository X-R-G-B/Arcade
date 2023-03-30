/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "IDisplayModule.hpp"
#include "SystemManager.hpp"

namespace Arcade {

    namespace ECS {
        enum class CompType : int {
            TEXT = 0,
            SPRITE = 1,
            MUSIC = 2,
            WINDOW = 3,
            SFTEXT = 4,
            SFSPRITE = 5,
            SFMUSIC = 6
        };
    }

    namespace Sfml {

        class DisplayModule : public Graph::IDisplayModule {
            public:
                DisplayModule();
                ~DisplayModule();
                void update(float delta,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &entityManager) final;
            private:
                ECS::SystemManager _systems;
                sf::RenderWindow _win;
        };
    }
}
