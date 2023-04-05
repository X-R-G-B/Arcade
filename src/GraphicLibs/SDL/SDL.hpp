/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDL
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "IDisplayModule.hpp"
#include "SystemManager.hpp"

namespace Arcade {
    namespace ECS {
        enum class CompType : int {
            TEXT = 0,
            SPRITE = 1,
            MUSIC = 2,
            SDLTEXT = 7,
            SDLSPRITE = 8,
            SDLMUSIC = 9
        };
    }
}
