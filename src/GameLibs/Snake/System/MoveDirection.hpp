/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MoveDirection
*/

#pragma once

#include "ISystem.hpp"
#include "ChangeDir.hpp"

namespace Snake {
    namespace System {
        class MoveDirection : public Arcade::ECS::ISystem {
            public:
                MoveDirection() = default;
                ~MoveDirection() = default;

                void run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &entityManager) final;
            private:
            void checkHitChangeDir(std::shared_ptr<Snake::Component::ChangeDir> changeDir, std::shared_ptr<Arcade::ECS::IEntity> entity);
        };
    }
}