/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml
*/

#include "Music.hpp"

Arcade::Sfml::MusicSystem::MusicSystem(sf::RenderWindow &win) : _win(win)
{
}

void Arcade::Sfml::MusicSystem::handleComponent(ECS::IComponent &IComp, ECS::IEntity &entity)
{
    ECS::IComponent comp;
    Graph::IMusic &MusicComp = static_cast<Graph::IMusic&>(IComp);
    Music *music;

    try {
        entity.getComponents(MusicComp.id + "_Sfml");
        entity.addComponent(std::make_unique<Music>(MusicComp.id + "_Sfml", MusicComp.path, MusicComp.loop, MusicComp.play));
    } catch (std::exception &e) {
    }
    comp = entity.getComponents(MusicComp.id + "_Sfml");
    if (comp.type != ECS::CompType::SFMUSIC) {
        return;
    }
    music = static_cast<Music*>(&comp);
    if (MusicComp.play && music->music.getStatus() != sf::SoundSource::Status::Playing) {
        music->music.play();
    } else if (MusicComp.play == false && music->music.getStatus() == sf::SoundSource::Status::Playing) {
        music->music.stop();
    }
}

void Arcade::Sfml::MusicSystem::run(float deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    std::unique_ptr<std::vector<std::shared_ptr<ECS::IEntity>>> _containMusicEntities =
        currentEntityManager.getEntitiesByComponentType(ECS::CompType::MUSIC);
    std::vector<std::shared_ptr<ECS::IComponent>> _components;

    for (auto const &entity : *(_containMusicEntities.get())) {
        _components = entity->getComponents(ECS::CompType::MUSIC);
        for (auto const &component : _components) {
            handleComponent(*(component.get()), *(entity.get()));
        }
    }
}

Arcade::Sfml::Music::Music(const std::string id, const std::string &path,
    bool loop, bool play)
{
    sf::Texture texture;

    this->id = id;
    this->type = ECS::CompType::SFMUSIC;
    if (!this->music.openFromFile(path)) {
        //TODO put right error type 
        throw std::invalid_argument("Wrong path for music : " + path);
    }
    if (play) {
        this->music.play();
    }
    this->music.setLoop(loop);
}
