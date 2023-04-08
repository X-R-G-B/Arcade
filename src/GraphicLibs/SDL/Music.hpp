/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Music
*/

#pragma once

#include "SDL.hpp"
#include "IMusic.hpp"
#include <string>

namespace Arcade {
    namespace SDL {
        class SDLMusic : public ECS::IComponent {
            public:
                SDLMusic(const std::string id, const std::string &path,
                bool loop, bool play);
                ~SDLMusic();

                Mix_Music *music;
        };

        class MusicSystem : public ECS::ISystem {
            public:
                MusicSystem(SDL_Renderer *win, std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &components);
                void run(double deltaTime,
                         ECS::IEventManager &eventManager,
                         ECS::IEntityManager &entityManager) final;
            private:
                SDL_Renderer *_win;
                std::vector<std::shared_ptr<ECS::IComponent>> &_components;
                std::shared_ptr<SDLMusic> getComponent(std::shared_ptr<Graph::IMusic> TextComp, const std::string &idEntity);
                void handleComponent(std::shared_ptr<Graph::IMusic> TextComp, const std::string &idEntity);
        };
    }
}
