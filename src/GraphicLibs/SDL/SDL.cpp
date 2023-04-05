/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDL
*/

#include "SDL.hpp"
#include "Sprite.hpp"
#include "Text.hpp"
#include "Api.hpp"
#include "Exceptions.hpp"

Arcade::SDL::DisplayModule::DisplayModule()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    this->_win = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);
    if (this->_win == nullptr) {
        throw ArcadeExceptions("Unexpected error caugth");
    }
    this->_renderer = SDL_CreateRenderer(this->_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (this->_renderer == nullptr) {
        throw ArcadeExceptions("ici error caugth");
    }
    this->_systems.addSystem("textSystem", std::make_unique<TextSystem>(this->_renderer, this->_components));
    this->_systems.addSystem("spriteSystem", std::make_unique<SpriteSystem>(this->_renderer, this->_components));
    _systems.addSystem("eventHandler", std::make_unique<EventHandler>());
}

Arcade::SDL::DisplayModule::~DisplayModule()
{
    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_win);
    SDL_Quit();
}

void Arcade::SDL::DisplayModule::update(double delta, Arcade::ECS::IEventManager &eventManager,
                                        Arcade::ECS::IEntityManager &entityManager)
{
    SDL_RenderClear(this->_renderer);
    _systems.update(delta, eventManager, entityManager);
    SDL_RenderPresent(this->_renderer);
}

extern "C" LibType getType()
{
    return LibType::GRAPH;
}

extern "C" const char *getName()
{
    return "SDL";
}

extern "C" Arcade::Graph::IDisplayModule *getDisplayModule()
{
    return new Arcade::SDL::DisplayModule();
}

extern "C" void destroyDisplayModule(Arcade::Graph::IDisplayModule *mod)
{
    delete mod;
}
