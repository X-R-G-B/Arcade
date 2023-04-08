/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** CheckDisappearingBodies
*/

#pragma once

#include "ISystem.hpp"
#include "Sprite.hpp"
#include "SnakeGrow.hpp"
#include "Forward.hpp"

namespace Nibbler {
    namespace System {
        class CheckDisappearingBodies : public Arcade::ECS::ISystem {
            public:
                void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentEntityManager) final;

            protected:
            private:
                void addNewBodyPartToSnake(Arcade::ECS::IEntityManager &entityManager, int idNbr);
                void placeNewBody(
                Arcade::ECS::IEntityManager &entityManager, std::shared_ptr<Nibbler::Component::Forward> &forward,
                Arcade::Graph::ISprite &newBody, int size);
                Nibbler::Direction getDirection(Arcade::Vector3f &lastBodyPos, Arcade::Vector3f pos);
                std::shared_ptr<Arcade::ECS::IEntity> getLastBody(Arcade::ECS::IEntityManager &entityManager, int size);
                Nibbler::Component::Forward &getMovableFromBodyEntity(std::shared_ptr<Arcade::ECS::IEntity> entity);
                Arcade::Graph::Sprite &getSpriteFromBodyEntity(std::shared_ptr<Arcade::ECS::IEntity> entity);
        };
    }
}
