/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Text
*/

#include "Text.hpp"
#include "Exceptions.hpp"

Arcade::SDL::SDLText::SDLText(const std::string id, const std::string &path,
                              const std::string &text, const Graph::Color &textColor,
                              const Arcade::Vector3f &pos, SDL_Renderer *win)
{
    SDL_Surface *surface;
    SDL_Color SDLtextColor = {(uint8_t) textColor.r,
                              (uint8_t) textColor.g,
                              (uint8_t) textColor.b,
                              (uint8_t) textColor.a };
    SDL_Rect SDLrect;

    if (win == nullptr) {
        throw ArcadeExceptions("Unexpected error was caugth");
    }
    this->_win = win;
    this->id = id;
    this->type = Arcade::ECS::CompType::SDLTEXT;
    this->_font = TTF_OpenFont(path.data(), 24);
    if (this->_font == nullptr) {
        throw ArcadeExceptions("Wrong path for sprite : " + path);
    }
    surface = TTF_RenderText_Solid(this->_font, text.data(), SDLtextColor);
    if (surface == nullptr) {
        TTF_CloseFont(this->_font);
        throw ArcadeExceptions("Unable to load surface");
    }
    this->_text = SDL_CreateTextureFromSurface(this->_win, surface);
    if (this->_text == nullptr) {
        SDL_FreeSurface(surface);
        throw ArcadeExceptions("Unable to load texture");
    }
    SDL_FreeSurface(surface);
}

Arcade::SDL::SDLText::~SDLText()
{
    TTF_CloseFont(this->_font);
    SDL_DestroyTexture(this->_text);
}
