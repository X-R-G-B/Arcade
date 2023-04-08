/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml
*/

#include "Sprite.hpp"
#include "Exceptions.hpp"

Arcade::Sfml::SpriteSystem::SpriteSystem(sf::RenderWindow &win, std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &components)
    : _win(win), _components(components)
{
}

std::shared_ptr<Arcade::Sfml::SfSprite> Arcade::Sfml::SpriteSystem::getComponent(std::shared_ptr<Graph::ISprite> SpriteComp, const std::string &idEntity)
{
    for (auto const &comp : _components) {
        if (comp->id == SpriteComp->id + idEntity) {
           return std::static_pointer_cast<SfSprite>(comp);
        }
    }

    std::shared_ptr<SfSprite> sprite = std::make_shared<SfSprite>(SpriteComp->id + idEntity, SpriteComp->path, SpriteComp->pos, SpriteComp->rect, _win);
    _components.push_back(sprite);
    return sprite;
}

void Arcade::Sfml::SpriteSystem::handleComponent(std::shared_ptr<Graph::ISprite> SpriteComp, const std::string &idEntity)
{
    std::shared_ptr<SfSprite> sprite = getComponent(SpriteComp, idEntity);
    sprite->sprite.setPosition(sf::Vector2f(SpriteComp->pos.x, SpriteComp->pos.y));
    sprite->sprite.setTextureRect(sf::Rect(SpriteComp->rect.top, SpriteComp->rect.left, SpriteComp->rect.height, SpriteComp->rect.width));
    _win.draw(sprite->sprite);
}

void Arcade::Sfml::SpriteSystem::run(double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    std::unique_ptr<std::vector<std::shared_ptr<Arcade::ECS::IEntity>>> entities;
 
    try {
        entities = currentEntityManager.getEntitiesByComponentType(ECS::CompType::SPRITE);
    } catch (const std::exception &e) {
        return;
    }
    if (entities.get() == nullptr) {
        return;
    }
    for (auto const &entity : *entities) {
        try {
            const std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &sprites =
                entity->getComponents(Arcade::ECS::CompType::SPRITE);
            for (auto const &sprite : sprites) {
                handleComponent(std::static_pointer_cast<Graph::ISprite>(sprite), entity->getId());
            }
        } catch (...) {
            continue;
        }
    }
}

Arcade::Sfml::SfSprite::SfSprite(const std::string id, const std::string &path,
    const Arcade::Vector3f &pos, Graph::Rect &rect, sf::RenderWindow &win) : _win(win)
{
    this->id = id;
    this->type = ECS::CompType::SFSPRITE;
    if (!this->texture.loadFromFile(path)) {
        throw ArcadeExceptions("Wrong path for sprite : " + path);
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(sf::Vector2f(pos.x, pos.y));
    this->sprite.setTextureRect(sf::Rect(rect.top, rect.left, rect.height, rect.width));
}
