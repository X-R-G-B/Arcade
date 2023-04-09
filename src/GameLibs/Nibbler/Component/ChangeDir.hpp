/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake Move System
*/

#pragma once

#include <string>
#include "ArcadeStruct.hpp"
#include "Direction.hpp"
#include "IComponent.hpp"

namespace Nibbler {
    namespace Component {
        class ChangeDir : public Arcade::ECS::IComponent {
            public:
                ChangeDir(const std::string &id, const Direction &direction, const Arcade::Vector2f &pos);
                ~ChangeDir() = default;
 
                Direction direction;
                Arcade::Vector2f pos;
        };
    }
}
