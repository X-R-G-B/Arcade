/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sprite
*/

#include "Sprite.hpp"
#include "Exceptions.hpp"

Arcade::SDL::SpriteSystem::SpriteSystem(SDL_Renderer *renderer)
    : _win(renderer)
{

}

void Arcade::SDL::SpriteSystem::handleComponent(ECS::IComponent &IComp, ECS::IEntity &entity)
{
    Graph::ISprite &SpriteComp = static_cast<Graph::ISprite &>(IComp);
    SDL_Rect dest;

    try {
        entity.addComponent(std::make_shared<SDL::SDLSprite>(SpriteComp.id + "_SDL", SpriteComp.path, SpriteComp.pos, SpriteComp.rect, this->_win));
    } catch (std::exception &e) {
    }
    ECS::IComponent &comp = entity.getComponents(SpriteComp.id + "_SDL");
    if (comp.type != ECS::CompType::SDLSPRITE) {
        return;
    }
    SDL::SDLSprite &sprite = static_cast<SDL::SDLSprite &>(comp);
    dest.x = SpriteComp.pos.x;
    dest.y = SpriteComp.pos.y;
    dest.h = SpriteComp.rect.height;
    dest.w = SpriteComp.rect.width;
    SDL_QueryTexture(sprite._sprite, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(sprite._win, sprite._sprite, NULL, &dest);
    SDL_RenderPresent(this->_win);
}

void Arcade::SDL::SpriteSystem::run(float deltaTime,
                               ECS::IEventManager &eventManager,
                               ECS::IEntityManager &entityManager)
{
    std::unique_ptr<std::vector<std::shared_ptr<ECS::IEntity>>> spriteEntities =
            entityManager.getEntitiesByComponentType(ECS::CompType::SPRITE);
    std::vector<std::shared_ptr<ECS::IComponent>> components;

    for (auto const &entity : *(spriteEntities.get())) {
        components = entity->getComponents(ECS::CompType::SPRITE);
        for (auto const &component : components) {
            this->handleComponent(*(component.get()), *(entity.get()));
        }
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
    SDL_QueryTexture(_sprite, NULL, NULL, &dest.w, &dest.h);
}

Arcade::SDL::SDLSprite::~SDLSprite()
{
    SDL_DestroyTexture(_sprite);
}
