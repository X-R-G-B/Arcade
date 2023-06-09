/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sprite
*/

#include "Sprite.hpp"
#include "Exceptions.hpp"

Arcade::SDL::SpriteSystem::SpriteSystem(SDL_Renderer &renderer,
    std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &components)
    : _win(renderer), _components(components)
{
}

SDL_Texture &Arcade::SDL::SDLSprite::getSprite()
{
    return (*this->_sprite);
}

std::shared_ptr<Arcade::SDL::SDLSprite> Arcade::SDL::SpriteSystem::getComponent(std::shared_ptr <Graph::ISprite> SpriteComp, const std::string &idEntity)
{
    for (auto const &comp : this->_components) {
        if (comp->id == SpriteComp->id + idEntity) {
            return (std::static_pointer_cast<SDLSprite>(comp));
        }
    }

    std::shared_ptr<SDLSprite> sprite = std::make_shared<SDLSprite>(SpriteComp->id + idEntity, SpriteComp->path, SpriteComp->pos, SpriteComp->rect, this->_win);
    _components.push_back(sprite);
    return (sprite);
}

void Arcade::SDL::SpriteSystem::handleComponent(std::shared_ptr<Graph::ISprite> SpriteComp, const std::string &idEntity)
{
    std::shared_ptr<SDLSprite> sprite = this->getComponent(SpriteComp, idEntity);

    sprite->_rect.x = SpriteComp->pos.x;
    sprite->_rect.y = SpriteComp->pos.y;
    sprite->_rect.w = SpriteComp->rect.width;
    sprite->_rect.h = SpriteComp->rect.height;
    SDL_QueryTexture(&(sprite->getSprite()), NULL, NULL, &sprite->_rect.w, &sprite->_rect.h);
    SDL_RenderCopy(&sprite->_win, &sprite->getSprite(), NULL, &sprite->_rect);
}

void Arcade::SDL::SpriteSystem::run(double deltaTime,
                               ECS::IEventManager &eventManager,
                               ECS::IEntityManager &entityManager)
{
    std::unique_ptr<std::vector<std::shared_ptr<Arcade::ECS::IEntity>>> entities;
 
    try {
        entities = entityManager.getEntitiesByComponentType(ECS::CompType::SPRITE);
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

Arcade::SDL::SDLSprite::SDLSprite(const std::string id, const std::string &path,
                                  const Arcade::Vector3f &pos, Graph::Rect &rect,
                                  SDL_Renderer &renderer)
    : _win(renderer)
{
    SDL_Rect dest;

    dest.x = pos.x;
    dest.y = pos.y;
    dest.w = rect.width;
    dest.h = rect.height;
    this->_sprite = IMG_LoadTexture(&renderer, path.data());
    if (_sprite == nullptr) {
        throw ArcadeExceptions("Wrong path for sprite : " + path);
    }
    this->id = id;
    this->type = ECS::CompType::SDLSPRITE;
    this->_rect = dest;
    SDL_QueryTexture(_sprite, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(&this->_win, this->_sprite, NULL, &dest);
}

Arcade::SDL::SDLSprite::~SDLSprite()
{
    SDL_DestroyTexture(_sprite);
}
