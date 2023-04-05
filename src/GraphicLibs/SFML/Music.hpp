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

        struct SfMusic : public ECS::IComponent {
            public:
                SfMusic(const std::string id, const std::string &path,
                    bool loop, bool play);
                sf::Music music;
        };

        class MusicSystem : public ECS::ISystem {
            public:
                MusicSystem(sf::RenderWindow &win, std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &components);
                void run(double deltaTime,
                    ECS::IEventManager &eventManager,
                    ECS::IEntityManager &entityManager) final;
            private:
                sf::RenderWindow &_win;
                std::vector<std::shared_ptr<ECS::IComponent>> &_components;
                std::shared_ptr<SfMusic> getComponent(std::shared_ptr<Graph::IMusic> TextComp);
                void handleComponent(std::shared_ptr<Graph::IMusic> TextComp);
        };
    }
}
