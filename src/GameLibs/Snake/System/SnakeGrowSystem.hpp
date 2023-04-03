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

namespace Snake {
    class SnakeGrowSystem : public Arcade::ECS::ISystem {
        public:
            SnakeGrowSystem() = default;
            ~SnakeGrowSystem() = default;
            void run(float deltaTime, Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &currentScene);
            Arcade::Graph::Sprite &getSpriteFromBodyEntity(std::shared_ptr<Arcade::ECS::IEntity> entity);
            Snake::Component::Forward &getMovableFromBodyEntity(std::shared_ptr<Arcade::ECS::IEntity> entity);
            Arcade::Vector3f getPositionForNewBody(Arcade::ECS::IEntityManager &currentScene);
            void addNewBodyPartToSnake(Arcade::ECS::IEntityManager &currentScene, int idNbr);
    };
}
