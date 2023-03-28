/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml
*/

#include "Sprite.hpp"

Arcade::Sfml::SpriteSystem::SpriteSystem(sf::RenderWindow &win) : _win(win)
{
}

void Arcade::Sfml::SpriteSystem::handleComponent(ECS::IComponent &IComp, ECS::IEntity &entity)
{
    Graph::ISprite *SpriteComp = dynamic_cast<Graph::ISprite*>(&IComp);
    Sprite *sprite = nullptr;

    try {
        entity.getComponents(SpriteComp->id + "_Sfml");
        entity.addComponent(std::make_unique<Sprite>(SpriteComp->id + "_Sfml", SpriteComp->path, SpriteComp->pos, SpriteComp->rect));
    } catch (std::exception &e) {
    }
    sprite = dynamic_cast<Sprite*>(&entity.getComponents(SpriteComp->id + "_Sfml"));
    _win.draw(sprite->sprite);
}

void Arcade::Sfml::SpriteSystem::run(float deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    std::unique_ptr<std::vector<std::shared_ptr<ECS::IEntity>>> _containSpriteEntities =
        currentEntityManager.getEntitiesByComponentType(ECS::CompType::SPRITE);
    std::vector<std::shared_ptr<ECS::IComponent>> _components;

    for (auto const &entity : *(_containSpriteEntities.get())) {
        _components = entity->getComponents(ECS::CompType::SPRITE);
        for (auto const &component : _components) {
            handleComponent(*(component.get()), *(entity.get()));
        }
    }
}

Arcade::Sfml::Sprite::Sprite(const std::string id, const std::string &path,
    const Arcade::Vector3f &pos, Graph::Rect &rect)
{
    sf::Texture texture;

    this->id = id;
    this->type = ECS::CompType::SFSPRITE;
    if (!texture.loadFromFile(path)) {
        //TODO put right error type 
        throw std::invalid_argument("Wrong path for sprite : " + path);
    }
    this->sprite.setTexture(texture);
    this->sprite.setPosition(sf::Vector2f(pos.x, pos.y));
    this->sprite.setTextureRect(sf::Rect(rect.top, rect.left, rect.height, rect.width));
}
