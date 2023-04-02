/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Component to tag entity that represent body
*/

#pragma once

#include "IComponent.hpp"

namespace Snake {
    namespace Component {
        class BodyComp : public Arcade::ECS::IComponent {
            public:
                BodyComp();
                ~BodyComp() = default;
        };
    }
}
