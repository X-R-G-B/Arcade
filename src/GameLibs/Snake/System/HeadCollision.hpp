/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFML_EventHandler
*/

#pragma once

#include "ISystem.hpp"
#include "Sprite.hpp"

namespace Snake {
    namespace System {
        class HeadCollision : public Arcade::ECS::ISystem {
            void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentScene) final;
            private:
                bool checkCollision(Arcade::ECS::IComponent &fst, std::shared_ptr<Arcade::Graph::Sprite> &head);
        };
    }
}
