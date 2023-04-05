/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Text
*/

#pragma once

#include "ISystem.hpp"
#include "MiniAudioWrapper.hpp"

namespace Ncurses {
    namespace System {
        class MusicSystem : public Arcade::ECS::ISystem {
            public:
                void run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &entityManager) final;
            private:
                MiniAudio::MiniAudioWrapper _miniAudioWrapper;
        };
    }
}
