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
        class SpriteSystem : public ECS::ISystem {
            public:
                SpriteSystem(SDL_Renderer *renderer);
                void run(float deltaTime,
                         ECS::IEventManager &eventManager,
                         ECS::IEntityManager &entityManager) final;
            private:
                SDL_Renderer *_win;
                void handleComponent(ECS::IComponent &comp, ECS::IEntity &entity);
        };

        class SDLSprite : public ECS::IComponent {
            public:
                SDLSprite(const std::string id, const std::string &path,
                          const Arcade::Vector3f &pos, Graph::Rect &rect,
                          SDL_Renderer *renderer);

                ~SDLSprite();
                SDL_Renderer *_win;
                SDL_Texture *_sprite;
                SDL_Rect rect;
            };
        }
}
