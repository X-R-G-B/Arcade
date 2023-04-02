/*
** EPITECH PROJECT, 2023
** Arcade Promo 2026 Toulouse
** File description:
** SnakeMapEntity
*/

#pragma once


#include "Entity.hpp"

namespace Snake {
    namespace Component {
        class SnakeMapEntity : public Arcade::ECS::Entity {
            public:
                SnakeMapEntity(const std::string &id) : Entity(id) {
                    this->type = Arcade::ECS::CompType::SNAKE_MAP;
                }
                ~SnakeMapEntity() = default;
        };
    }
}
