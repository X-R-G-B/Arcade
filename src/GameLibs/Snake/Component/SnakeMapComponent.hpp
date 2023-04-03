/*
** EPITECH PROJECT, 2023
** Arcade Promo 2026 Toulouse
** File description:
** SnakeMapComponent
*/

#pragma once

#include "Sprite.hpp"
#include "SnakeCompType.hpp"
#include "MagicValue.hpp"

namespace Snake {
    namespace Component {
        class SnakeMapComponent : public Arcade::Graph::Sprite {
            public:
                SnakeMapComponent(const std::string &id, const Arcade::Vector3f &pos);
        };
    }
}
