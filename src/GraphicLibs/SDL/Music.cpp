/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Music
*/

#include "Music.hpp"
#include "Exceptions.hpp"

Arcade::SDL::MusicSystem::MusicSystem(SDL_Renderer *win, std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &components)
    : _win(win), _components(components)
{
}

std::shared_ptr<Arcade::SDL::SDLMusic> Arcade::SDL::MusicSystem::getComponent(std::shared_ptr<Graph::IMusic> MusicComp)
{
    for (auto const &comp : _components) {
        if (comp->id == MusicComp->id) {
            return std::static_pointer_cast<SDLMusic>(comp);
        }
    }

    std::shared_ptr<SDLMusic> music = std::make_shared<SDLMusic>(MusicComp->id, MusicComp->path, MusicComp->loop, MusicComp->play);
    _components.push_back(music);
    return music;
}

void Arcade::SDL::MusicSystem::handleComponent(std::shared_ptr<Graph::IMusic> MusicComp)
{
    std::shared_ptr<SDLMusic> music = getComponent(MusicComp);

    if (MusicComp->play && MusicComp->loop) {
        Mix_PlayMusic(music->music, -1);
    } else if (MusicComp->play) {
        Mix_PlayMusic(music->music, 1);
    } else {
        Mix_HaltMusic();
    }
}

void Arcade::SDL::MusicSystem::run(double deltaTime, ECS::IEventManager &eventManager, ECS::IEntityManager &entityManager)
{
    std::unique_ptr<std::vector<std::shared_ptr<Arcade::ECS::IComponent>>> musicComponents;
 
    try {
        musicComponents = entityManager.getComponentsByComponentType(ECS::CompType::MUSIC);
    } catch (const std::exception &e) {
        return;
    }
    if (musicComponents == nullptr) {
        return;
    }
    for (auto const &music : *musicComponents) {
        handleComponent(std::static_pointer_cast<Graph::IMusic>(music));
    }
}

Arcade::SDL::SDLMusic::SDLMusic(const std::string id, const std::string &path,
             bool loop, bool play)
{
    this->id = id;
    this->type = Arcade::ECS::CompType::SDLMUSIC;
    this->music = Mix_LoadMUS(path.data());
    if (music == nullptr) {
        throw ArcadeExceptions("Wrong path for music : " + path);
    }
    if (play && loop) {
        Mix_PlayMusic(this->music, -1);
    }
    if (play) {
        Mix_PlayMusic(this->music, 1);
    }
}

Arcade::SDL::SDLMusic::~SDLMusic()
{
    Mix_FreeMusic(this->music);
}
