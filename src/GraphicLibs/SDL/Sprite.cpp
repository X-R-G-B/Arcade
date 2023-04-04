/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sprite
*/

#include "Sprite.hpp"
#include "Exceptions.hpp"

Arcade::SDL::SDLSprite::SDLSprite(const std::string id, const std::string &path,
                                  const Arcade::Vector3f &pos, Graph::Rect &rect, SDL_Window &window,
                                  SDL_Renderer *renderer)
                                  : _win(window)
{
    SDL_Surface *sprite;
    SDL_Rect dest;

    dest.x = pos.x;
    dest.y = pos.y;
    dest.w = rect.width;
    dest.h = rect.height;
    if (renderer == nullptr) {
        ArcadeExceptions("Unexpected error caught.");
    }
    sprite = SDL_LoadBMP(path.data());
    if (sprite == nullptr) {
        throw ArcadeExceptions("Wrong path for sprite : " + path);
    }
    this->id = id;
    this->type = ECS::CompType::SDLSPRITE;
    this->_sprite = SDL_CreateTextureFromSurface(renderer, sprite);
    SDL_QueryTexture(_sprite, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(renderer, _sprite, NULL, &dest);
    SDL_FreeSurface(sprite);
}

Arcade::SDL::SDLSprite::~SDLSprite()
{
    SDL_DestroyTexture(_sprite);
}
