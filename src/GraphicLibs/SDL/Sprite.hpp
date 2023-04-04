/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sprite
*/

#pragma once

#include "SDL.hpp"
#include "ISprite.hpp"

namespace Arcade {
    namespace SDL {
    class SDLSprite : public ECS::IComponent {
        public:
            SDLSprite(const std::string id, const std::string &path,
                      const Arcade::Vector3f &pos, Graph::Rect &rect, SDL_Window &window,
                      SDL_Renderer *renderer);

            ~SDLSprite();
            SDL_Window &_win;
            SDL_Texture *_sprite;
            SDL_Rect rect;
        };
    }
}