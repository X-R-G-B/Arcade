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
    Graph::IMusic *MusicComp = dynamic_cast<Graph::IMusic*>(&IComp);
    Music *music = nullptr;

    try {
        entity.getComponents(MusicComp->id + "_Sfml");
        entity.addComponent(std::make_unique<Music>(MusicComp->id + "_Sfml", MusicComp->path, MusicComp->pos, MusicComp->rect));
    } catch (std::exception &e) {
    }
    music = dynamic_cast<Music*>(&entity.getComponents(MusicComp->id + "_Sfml"));
    _win.draw(music->music);
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
    const Arcade::Vector3f &pos, Graph::Rect &rect)
{
    sf::Texture texture;

    this->id = id;
    this->type = ECS::CompType::SFMUSIC;
    if (!texture.loadFromFile(path)) {
        //TODO put right error type 
        throw std::invalid_argument("Wrong path for music : " + path);
    }
    this->music.setTexture(texture);
    this->music.setPosition(sf::Vector2f(pos.x, pos.y));
    this->music.setTextureRect(sf::Rect(rect.top, rect.left, rect.height, rect.width));
}
