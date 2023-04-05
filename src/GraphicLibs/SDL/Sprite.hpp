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
                      const Arcade::Vector3f &pos, Graph::Rect &rect,
                      SDL_Renderer *renderer);
            ~SDLSprite();

            SDL_Renderer *_win;
            SDL_Texture *_sprite;
            SDL_Rect _rect;
        };

        class SpriteSystem : public ECS::ISystem {
            public:
                SpriteSystem(SDL_Renderer *renderer,
                             std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &components);
                void run(double deltaTime,
                         ECS::IEventManager &eventManager,
                         ECS::IEntityManager &entityManager) final;
            private:
                SDL_Renderer *_win;
                std::vector<std::shared_ptr<ECS::IComponent>> &_components;
                std::shared_ptr<SDLSprite> getComponent(std::shared_ptr<Graph::ISprite> SpriteComp);
                void handleComponent(std::shared_ptr<Graph::ISprite> SpriteComp);
        };
    }
}
