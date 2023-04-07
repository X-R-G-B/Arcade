/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Text
*/

#include "SDL.hpp"
#include "IText.hpp"
#include "ISystem.hpp"

namespace Arcade {
    namespace SDL {
        class SDLText : public ECS::IComponent {
            public:
                SDLText(const std::string id, const std::string &path,
                        const std::string &text, const Graph::Color &textColor,
                        const Arcade::Vector3f &pos, SDL_Renderer *win);
                ~SDLText();

                SDL_Renderer *_win;
                TTF_Font *_font;
                SDL_Texture *_text;
                SDL_Rect _rect;

        };

        class TextSystem : public ECS::ISystem {
            public:
                TextSystem(SDL_Renderer *win,
                           std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &components);
                void run(double deltaTime,
                         ECS::IEventManager &eventManager,
                         ECS::IEntityManager &entityManager) final;
            private:
                SDL_Renderer *_win;
                std::vector<std::shared_ptr<ECS::IComponent>> &_components;
                std::shared_ptr<SDLText> getComponent(std::shared_ptr<Graph::IText> TextComp);
                void handleComponent(std::shared_ptr<Graph::IText> TextComp);

        };
    }
}
