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
        class Forward : public Arcade::ECS::IComponent {
            public:
                Forward(const std::string &id, const Direction &direction);
                ~Forward() = default;
 
                Direction direction;
        };
    }
}
