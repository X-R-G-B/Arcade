/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml
*/

#include "Sprite.hpp"
#include "Exceptions.hpp"

Arcade::Sfml::SpriteSystem::SpriteSystem(sf::RenderWindow &win) : _win(win)
{
}

void Arcade::Sfml::SpriteSystem::handleComponent(ECS::IComponent &IComp, ECS::IEntity &entity)
{
    Graph::ISprite &SpriteComp = static_cast<Graph::ISprite&>(IComp);

    try {
        entity.addComponent(std::make_shared<SfSprite>(SpriteComp.id + "_Sfml", SpriteComp.path, SpriteComp.pos, SpriteComp.rect, _win));
    } catch (std::exception &e) {
    }
    ECS::IComponent &comp = entity.getComponents(SpriteComp.id + "_Sfml");
    if (comp.type != ECS::CompType::SFSPRITE) {
        return;
    }
    SfSprite &sprite = static_cast<SfSprite&>(comp);
    sprite.setPosition(SpriteComp.pos);
    sprite.sprite.setTextureRect(sf::Rect(SpriteComp.rect.top, SpriteComp.rect.left, SpriteComp.rect.height, SpriteComp.rect.width));
    _win.draw(sprite.sprite);
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

Arcade::Sfml::SfSprite::SfSprite(const std::string id, const std::string &path,
    const Arcade::Vector3f &pos, Graph::Rect &rect, sf::RenderWindow &win) : _win(win)
{
    sf::Texture texture;

    this->id = id;
    this->type = ECS::CompType::SFSPRITE;
    if (!texture.loadFromFile(path)) {
        throw ArcadeExceptions("Wrong path for sprite : " + path);
    }
    this->sprite.setTexture(texture);
    setPosition(pos);
    this->sprite.setTextureRect(sf::Rect(rect.top, rect.left, rect.height, rect.width));
}

void Arcade::Sfml::SfSprite::setPosition(const Arcade::Vector3f &pos)
{
    sf::Vector2u size = _win.getSize();
    this->sprite.setPosition(sf::Vector2f((pos.x / 100) * size.x, (pos.y / 100) * size.y));
}
