/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SnakeGrowSystem
*/

#pragma once

#include "ISystem.hpp"

namespace Snake {
    class SnakeGrowSystem : public ISystem {
        public:
            SnakeGrowSystem() = default;
            ~SnakeGrowSystem() = default;
            void run(float deltaTime, Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &currentScene);
            Arcade::Graph::Sprite &getSpriteFromBodyEntity(std::shared_ptr<Arcade::ECS::IEntity> entity);
            bool isInsideABody(std::vector<std::shared_ptr<Arcade::ECS::IEntity>> &bodies, Arcade::Vector3f &pos);
            Arcade::Vector3f getPositionForNewBody(Arcade::ECS::IEntityManager &currentScene);
            void addNewBodyPartToSnake(Arcade::ECS::IEntityManager &currentScene, int idNbr);
        private:
            std::size_t size = 4;
    };
}
