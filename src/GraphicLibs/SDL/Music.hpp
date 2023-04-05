/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Music
*/

#pragma once

#include "SDL.hpp"
#include "IMusic.hpp"

namespace Arcade {
    namespace SDL {
        class Music : public ECS::IComponent {
            public:
                Music(const std::string id, const std::string &path,
                bool loop, bool play);
                ~Music();
            protected:
            private:
                Mix_Music *music;
        };


    }
}
