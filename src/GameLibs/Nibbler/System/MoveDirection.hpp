/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MoveDirection
*/

#pragma once

#include "IComponent.hpp"
#include "ISystem.hpp"
#include "ChangeDir.hpp"

namespace Nibbler {
    namespace System {
        class MoveDirection : public Arcade::ECS::ISystem {
            public:
                MoveDirection() = default;
                ~MoveDirection() = default;

                void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &entityManager) final;
            private:
                bool checkHitChangeDir(
                std::shared_ptr<Nibbler::Component::ChangeDir> changeDir,
                std::shared_ptr<Arcade::ECS::IEntity> entity,
                Arcade::ECS::IComponent &lastSnakeBody);
        };
    }
}
