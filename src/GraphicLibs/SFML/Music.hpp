/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Music
*/

#pragma once

#include "IComponent.hpp"
#include "ISystem.hpp"
#include "GraphStruct.hpp"
#include "IMusic.hpp"
#include "Sfml.hpp"

namespace Arcade {

    namespace Sfml {

        class MusicSystem : public ECS::ISystem {
            public:
                MusicSystem(sf::RenderWindow &win);
                void run(float deltaTime,
                    ECS::IEventManager &eventManager,
                    ECS::IEntityManager &entityManager) final;
            private:
                sf::RenderWindow &_win;
                void handleComponent(ECS::IComponent &comp, ECS::IEntity &entity);

        };

        struct Music : public ECS::IComponent {
            public:
                Music(const std::string id, const std::string &path,
                    const Arcade::Vector3f &pos, Graph::Rect &rect);
                sf::Music music;
        };
    }
}
