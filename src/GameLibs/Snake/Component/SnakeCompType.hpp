/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake Move System
*/

#pragma once

#include "IComponent.hpp"

namespace Arcade {
    namespace ECS {
        enum class CompType : int {
            TEXT = 0,
            SPRITE = 1,
            MUSIC = 2,
            MOVEABLE = 101
        };
    }
}
