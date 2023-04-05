/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sprite
*/

#include "Sprite.hpp"
#include "Exceptions.hpp"

Arcade::SDL::SpriteSystem::SpriteSystem(SDL_Renderer *renderer,
    std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &components)
    : _win(renderer), _components(components)
{
}

std::shared_ptr<Arcade::SDL::SDLSprite> Arcade::SDL::SpriteSystem::getComponent(std::shared_ptr <Graph::ISprite> SpriteComp)
{
    for (auto const &comp : this->_components) {
        if (comp->id == SpriteComp->id) {
            return (std::static_pointer_cast<SDLSprite>(comp));
        }
    }

    std::shared_ptr<SDLSprite> sprite = std::make_shared<SDLSprite>(SpriteComp->id, SpriteComp->path, SpriteComp->pos, SpriteComp->rect, this->_win);
    _components.push_back(sprite);
    return (sprite);
}
void Arcade::SDL::SpriteSystem::handleComponent(std::shared_ptr<Graph::ISprite> SpriteComp)
{
    std::shared_ptr<SDLSprite> sprite = this->getComponent(SpriteComp);

    SDL_QueryTexture(sprite->_sprite, NULL, NULL, &sprite->_rect.w, &sprite->_rect.h);
    SDL_RenderCopy(sprite->_win, sprite->_sprite, NULL, &sprite->_rect);
}

void Arcade::SDL::SpriteSystem::run(double deltaTime,
                               ECS::IEventManager &eventManager,
                               ECS::IEntityManager &entityManager)
{
    std::unique_ptr<std::vector<std::shared_ptr<ECS::IComponent>>> spriteComponents =
            entityManager.getComponentsByComponentType(ECS::CompType::SPRITE);

        for (auto const &sprite : *(spriteComponents)) {
            this->handleComponent(std::static_pointer_cast<Graph::ISprite>(sprite));
        }
}

Arcade::SDL::SDLSprite::SDLSprite(const std::string id, const std::string &path,
                                  const Arcade::Vector3f &pos, Graph::Rect &rect,
                                  SDL_Renderer *renderer)
                                  : _win(renderer)
{
    SDL_Rect dest;

    dest.x = pos.x;
    dest.y = pos.y;
    dest.w = rect.width;
    dest.h = rect.height;
    if (renderer == nullptr) {
        throw ArcadeExceptions("Unexpected error was caugth");
    }
    this->_sprite = IMG_LoadTexture(renderer, path.data());
    if (_sprite == nullptr) {
        throw ArcadeExceptions("Wrong path for sprite : " + path);
    }
    this->id = id;
    this->type = ECS::CompType::SDLSPRITE;
    this->_rect = dest;
    SDL_QueryTexture(_sprite, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(this->_win, this->_sprite, NULL, &dest);
}

Arcade::SDL::SDLSprite::~SDLSprite()
{
    SDL_DestroyTexture(_sprite);
}
