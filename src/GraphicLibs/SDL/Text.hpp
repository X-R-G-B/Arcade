/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Text
*/

#include "SDL.hpp"
#include "IText.hpp"

namespace Arcade {
    namespace SDL {
        class SDLText : public ECS::IComponent {
            public:
                SDLText(const std::string id, const std::string &path,
                        const std::string &text, const Graph::Color &textColor,
                        const Arcade::Vector3f &pos, SDL_Renderer *win);
                ~SDLText();
            private:
                SDL_Renderer *_win;
                TTF_Font *_font;
                SDL_Texture *_text;

        };
    }
}
