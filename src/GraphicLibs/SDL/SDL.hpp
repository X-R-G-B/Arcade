/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDL
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "IDisplayModule.hpp"
#include "SystemManager.hpp"
#include "EventHandler.hpp"

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

    namespace SDL {
        class DisplayModule : public Graph::IDisplayModule {
        public:
            DisplayModule();
            ~DisplayModule();
            void update(float delta,
                        Arcade::ECS::IEventManager &eventManager,
                        Arcade::ECS::IEntityManager &entityManager) final;
        private:
            ECS::SystemManager _systems;
            SDL_Renderer *_renderer;
            SDL_Window *_win;
            std::vector<std::shared_ptr<ECS::IComponent>> _components;
        };
    }
}
