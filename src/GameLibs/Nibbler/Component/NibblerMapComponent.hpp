/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NibblerMapComponent
*/

#pragma once

#include "Sprite.hpp"

namespace Nibbler {
    namespace Component {
        class NibblerMapComponent : public Arcade::Graph::Sprite {
            public:
                NibblerMapComponent(const std::string &id, const Arcade::Vector3f &pos);
        };
    }
}
