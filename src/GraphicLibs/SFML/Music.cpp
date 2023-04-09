/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml
*/

#include "Music.hpp"
#include "Exceptions.hpp"
#include <string>

Arcade::Sfml::MusicSystem::MusicSystem(sf::RenderWindow &win, std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &components)
    : _win(win), _components(components)
{
}

std::shared_ptr<Arcade::Sfml::SfMusic> Arcade::Sfml::MusicSystem::getComponent(std::shared_ptr<Graph::IMusic> MusicComp, const std::string &idEntity)
{
    for (auto const &comp : _components) {
        if (comp->id == MusicComp->id + idEntity) {
           return std::static_pointer_cast<SfMusic>(comp);
        }
    }

    std::shared_ptr<SfMusic> music = std::make_shared<SfMusic>(MusicComp->id + idEntity, MusicComp->path, MusicComp->loop, MusicComp->play);
    _components.push_back(music);
    return music;
}

void Arcade::Sfml::MusicSystem::handleComponent(std::shared_ptr<Graph::IMusic> MusicComp, const std::string &idEntity)
{
    std::shared_ptr<SfMusic> music = getComponent(MusicComp, idEntity);
    if (MusicComp->play && music->music.getStatus() != sf::SoundSource::Status::Playing) {
        music->music.play();
    } else if (MusicComp->play == false && music->music.getStatus() == sf::SoundSource::Status::Playing) {
        music->music.stop();
    }
}

void Arcade::Sfml::MusicSystem::run(double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    std::unique_ptr<std::vector<std::shared_ptr<Arcade::ECS::IEntity>>> entities;
 
    try {
        entities = currentEntityManager.getEntitiesByComponentType(ECS::CompType::MUSIC);
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

Arcade::Sfml::SfMusic::SfMusic(const std::string id, const std::string &path,
    bool loop, bool play)
{
    this->id = id;
    this->type = ECS::CompType::SFMUSIC;
    if (!this->music.openFromFile(path)) {
        throw ArcadeExceptions("Wrong path for music : " + path);
    }
    if (play) {
        this->music.play();
    }
    this->music.setLoop(loop);
}
