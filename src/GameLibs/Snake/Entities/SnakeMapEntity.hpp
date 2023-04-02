/*
** EPITECH PROJECT, 2023
** Arcade Promo 2026 Toulouse
** File description:
** SnakeMapEntity
*/

#pragma once

#include "Entity.hpp"

namespace Snake {
    namespace Entity {
        class SnakeMapEntity : Arcade::ECS::Entity {
            public:
                SnakeMapEntity();
                ~SnakeMapEntity() = default;
        };
    }
}
