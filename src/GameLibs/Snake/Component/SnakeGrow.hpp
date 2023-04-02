/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SnakeGrow header
*/

#pragma once

#include <vector>
#include "IComponent.hpp"

namespace Snake {
    namespace Component {
        struct SnakeGrow : Arcade::ECS::IComponent {
            public:
                SnakeGrow(const std::string &id);
                int grow;
                int size;
        };
    }
}
