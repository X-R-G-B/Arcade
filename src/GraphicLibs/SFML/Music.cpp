/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml
*/

#include "Music.hpp"
#include "Exceptions.hpp"

Arcade::Sfml::MusicSystem::MusicSystem(sf::RenderWindow &win) : _win(win)
{
}

void Arcade::Sfml::MusicSystem::handleComponent(ECS::IComponent &IComp, ECS::IEntity &entity)
{
    ECS::IComponent comp;
    Graph::IMusic &MusicComp = static_cast<Graph::IMusic&>(IComp);

    try {
        entity.getComponents(MusicComp.id + "_Sfml");
        entity.addComponent(std::make_unique<SfMusic>(MusicComp.id + "_Sfml", MusicComp.path, MusicComp.loop, MusicComp.play));
    } catch (std::exception &e) {
    }
    comp = entity.getComponents(MusicComp.id + "_Sfml");
    if (comp.type != ECS::CompType::SFMUSIC) {
        return;
    }
    SfMusic &music = static_cast<SfMusic&>(comp);
    if (MusicComp.play && music.music.getStatus() != sf::SoundSource::Status::Playing) {
        music.music.play();
    } else if (MusicComp.play == false && music.music.getStatus() == sf::SoundSource::Status::Playing) {
        music.music.stop();
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
