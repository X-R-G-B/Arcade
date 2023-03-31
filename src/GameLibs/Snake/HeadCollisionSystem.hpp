/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFML_EventHandler
*/

#pragma once

#include "ISystem.hpp"

namespace Snake {
    class HeadCollisionSystem : public Arcade::ECS::ISystem {
        void run(float deltaTime,
            Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &currentScene) final;
        private:
            bool checkCollision(Arcade::Vector3f fst, Arcade::Vector3f scd);
    }
}
