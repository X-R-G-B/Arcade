/*
** EPITECH PROJECT, 2023
** Arcade Promo 2026 Toulouse
** File description:
** Components that will be added to entity
*/

#pragma once

#include "IComponent.hpp"

namespace Arcade {
    namespace ECS {
        /**
         * @brief The AComponents interface
         *
         * defaultComponent type to implement: TEXT, SPRITE, MUSIC
         */
        enum class CompType : int {
            TEXT = 0,
            SPRITE = 1,
            MUSIC = 2,
        };
    } // namespace ECS
};    // namespace Arcade
