/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake Move System
*/

#pragma once

#include <string>
#include "Direction.hpp"
#include "IComponent.hpp"

namespace Snake {
    namespace Component {
        class Moveable : public Arcade::ECS::IComponent {
            public:
                Moveable(const std::string &id, const Direction &direction);
                ~Moveable() = default;
 
                Direction direction;
        };
    }
}
