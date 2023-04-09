/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Music
*/

#include "Music.hpp"
#include "Exceptions.hpp"
#include <iostream>

Arcade::SDL::MusicSystem::MusicSystem(SDL_Renderer *win, std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &components)
    : _win(win), _components(components)
{
}

std::shared_ptr<Arcade::SDL::SDLMusic> Arcade::SDL::MusicSystem::getComponent(std::shared_ptr<Graph::IMusic> MusicComp, const std::string &idEntity)
{
    for (auto const &comp : _components) {
        if (comp->id == MusicComp->id + idEntity) {
            return std::static_pointer_cast<SDLMusic>(comp);
        }
    }

    std::shared_ptr<SDLMusic> music = std::make_shared<SDLMusic>(MusicComp->id + idEntity, MusicComp->path, MusicComp->loop, MusicComp->play);
    _components.push_back(music);
    return music;
}

void Arcade::SDL::MusicSystem::handleComponent(std::shared_ptr<Graph::IMusic> MusicComp, const std::string &idEntity)
{
    std::shared_ptr<SDLMusic> music = getComponent(MusicComp, idEntity);

    if (MusicComp->play && music->isPlaying == false) {
        Mix_PlayMusic(music->music, MusicComp->loop ? -1 : 1);

    }
}

void Arcade::SDL::MusicSystem::run(double deltaTime, ECS::IEventManager &eventManager, ECS::IEntityManager &entityManager)
{
    std::unique_ptr<std::vector<std::shared_ptr<Arcade::ECS::IEntity>>> entities;

    try {
        entities = entityManager.getEntitiesByComponentType(ECS::CompType::MUSIC);
    } catch (const std::exception &e) {
        return;
    }
    if (entities.get() == nullptr) {
        return;
    }
    for (auto const &entity : *entities) {
        try {
            const std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &sprites =
                entity->getComponents(Arcade::ECS::CompType::MUSIC);
            for (auto const &sprite : sprites) {
                handleComponent(std::static_pointer_cast<Graph::IMusic>(sprite), entity->getId());
            }
        } catch (...) {
            continue;
        }
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
    if (play) {
        Mix_PlayMusic(this->music, loop ? -1 : 1);
        this->isPlaying = true;
    } else {
        this->isPlaying = false;
    }
}

Arcade::SDL::SDLMusic::~SDLMusic()
{
    Mix_FreeMusic(this->music);
}
