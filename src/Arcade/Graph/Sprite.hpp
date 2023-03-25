/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** ASprite
*/

#pragma once

#include "ISprite.hpp"
#include "AComponent.hpp"

namespace Arcade {
    namespace Graph {
        class Sprite : public ISprite {
            public:
                Sprite(const std::string &id);
        };
    }
}
