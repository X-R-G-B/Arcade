/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Score
*/

#pragma once

#include "ISystem.hpp"

namespace Snake {
    namespace System {
        class Score : public Arcade::ECS::ISystem{
            public:
                Score();
                ~Score();

                void run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentScene) final;
            protected:
            private:
        };
    }
}
