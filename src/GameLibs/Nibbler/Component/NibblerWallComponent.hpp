/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NibblerWallComponent
*/

#pragma once

#include "Sprite.hpp"

namespace Nibbler {
    namespace Component {
        class NibblerWallComponent : public Arcade::Graph::Sprite {
            public:
                NibblerWallComponent(const std::string &id, const Arcade::Vector3f &pos);
        };
    }
}

