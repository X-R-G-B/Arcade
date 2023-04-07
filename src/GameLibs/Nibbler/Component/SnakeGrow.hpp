/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SnakeGrow header
*/

#pragma once

#include <string>
#include <vector>
#include "IComponent.hpp"

namespace Nibbler {
    namespace Component {
        struct SnakeGrow : Arcade::ECS::IComponent {
            public:
                SnakeGrow(const std::string &id);
                int grow;
                int size;
                std::string lastIdBodyComp;
        };
    }
}
