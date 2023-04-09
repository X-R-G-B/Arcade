/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SnakeGrowSystem
*/

#pragma once

#include "ISystem.hpp"
#include "Sprite.hpp"
#include "Forward.hpp"

namespace Nibbler {
    namespace System {
        class SnakeGrowSystem : public Arcade::ECS::ISystem {
            public:
                SnakeGrowSystem() = default;
                ~SnakeGrowSystem() = default;
                void run(double deltaTime,
                    Arcade::ECS::IEventManager &eventManager,
                    Arcade::ECS::IEntityManager &currentEntityManager) final;
                Arcade::Graph::Sprite &getSpriteFromBodyEntity(std::shared_ptr<Arcade::ECS::IEntity> entity);
                Nibbler::Component::Forward &getMovableFromBodyEntity(std::shared_ptr<Arcade::ECS::IEntity> entity);
                std::shared_ptr<Arcade::ECS::IEntity> getLastBody(Arcade::ECS::IEntityManager &entityManager, int size);
                Direction getDirection(Arcade::Vector3f &lastBodyPos, Arcade::Vector3f pos);
                void placeNewBody(Arcade::ECS::IEntityManager &entityManager,
                    std::shared_ptr<Nibbler::Component::Forward> &forward,
                    Arcade::Graph::ISprite &newBody, int size);
                void addNewBodyPartToSnake(Arcade::ECS::IEntityManager &entityManager, int idNbr);
        };
    }
}
