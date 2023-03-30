/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Music
*/

#pragma once

#include <SFML/Audio.hpp>
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

        struct SfMusic : public ECS::IComponent {
            public:
                SfMusic(const std::string id, const std::string &path,
                    bool loop, bool play);
                sf::Music music;
        };
    }
}
