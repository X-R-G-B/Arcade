/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EventHandler
*/

#pragma once

#include <SDL2/SDL_events.h>
#include "ISystem.hpp"

namespace Arcade {
    namespace SDL {
        class EventHandler : public Arcade::ECS::ISystem {
            public:
                EventHandler() = default;

                void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentScene) final;
            protected:
            private:
                void HandleEvents(Arcade::ECS::IEventManager &eventManager, SDL_Event &events);
                void HandleQuitEvent(Arcade::ECS::IEventManager &eventManager, SDL_Event &events);
                void HandleMouseEvent(Arcade::ECS::IEventManager &eventManager, SDL_Event &events);
                void HandleWindowEvent(Arcade::ECS::IEventManager &eventManager, SDL_Event &events);
                void HandleKeyboardEvent(Arcade::ECS::IEventManager &eventManager, SDL_Event &events);
        };
    }
}
