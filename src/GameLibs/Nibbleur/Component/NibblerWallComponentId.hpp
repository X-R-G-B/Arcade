/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NibblerWallComponentId
*/

#pragma once

#include "IComponent.hpp"

namespace Nibbler {
    namespace Component {
        class NibblerWallComponentId : public Arcade::ECS::IComponent {
            public:
                NibblerWallComponentId(const std::string &id);
        };
    }
}
