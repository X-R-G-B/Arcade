/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sprite
*/

#pragma once

#include <SDL2/SDL.h>
#include "CompType.hpp"
#include "ISprite.hpp"
#include "GraphStruct.hpp"

namespace Arcade {
    namespace SDL {
        class SDLSprite {
        public:
            SDLSprite(const std::string id, const std::string &path,
                      const Arcade::Vector3f &pos, Graph::Rect &rect, SDL_Window &window);

            ~SDLSprite() = default;

        protected:
        private:
        };
    }
}