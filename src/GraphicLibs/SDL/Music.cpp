/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Music
*/

#include "Music.hpp"
#include "Exceptions.hpp"

Arcade::SDL::Music::Music(const std::string id, const std::string &path,
             bool loop, bool play)
{
    this->id = id;
    this->type = Arcade::ECS::CompType::SDLMUSIC;
    this->music = Mix_LoadMUS(path.data());
    if (music = nullptr) {
        throw ArcadeExceptions("Wrong path for music : " + path);
    }
    if (play && loop) {
        Mix_PlayMusic(this->music, -1);
    }
    if (play) {
        Mix_PlayMusic(this->music, 1);
    }
}

Arcade::SDL::Music::~Music()
{
    Mix_FreeMusic(this->music);
}
