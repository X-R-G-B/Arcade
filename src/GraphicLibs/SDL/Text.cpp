/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Text
*/

#include "Text.hpp"
#include "Exceptions.hpp"

Arcade::SDL::TextSystem::TextSystem(SDL_Renderer *win, std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &components)
    : _win(win), _components(components)
{

}

std::shared_ptr<Arcade::SDL::SDLText> Arcade::SDL::TextSystem::getComponent(std::shared_ptr<Graph::IText> TextComp)
{
    for (auto const &comp : this->_components) {
        if (comp->id == TextComp->id) {
            return (std::static_pointer_cast<SDLText>(comp));
        }
    }

    std::shared_ptr<SDLText> text = std::make_shared<SDLText>(TextComp->id, TextComp->fontPath, TextComp->text, TextComp->textColor, TextComp->pos, this->_win);
    _components.push_back(text);
    return (text);
}

void Arcade::SDL::TextSystem::handleComponent(std::shared_ptr<Graph::IText> TextComp)
{
    std::shared_ptr<SDLText> text = this->getComponent(TextComp);

    SDL_RenderCopy(text->_win, text->_text, NULL, &text->_rect);
}

void Arcade::SDL::TextSystem::run(double deltaTime,
                                  ECS::IEventManager &eventManager,
                                  ECS::IEntityManager &entityManager)
{
    std::unique_ptr<std::vector<std::shared_ptr<Arcade::ECS::IComponent>>> textComponents;

    try {
        textComponents = entityManager.getComponentsByComponentType(ECS::CompType::TEXT);
    } catch (const std::exception &e) {
        return;
    }
    if (textComponents == nullptr) {
        return;
    }
    for (auto const &text : *(textComponents)) {
        this->handleComponent(std::static_pointer_cast<Graph::IText>(text));
    }
}

Arcade::SDL::SDLText::SDLText(const std::string id, const std::string &path,
                              const std::string &text, const Graph::Color &textColor,
                              const Arcade::Vector3f &pos, SDL_Renderer *win)
{
    SDL_Surface *surface;
    SDL_Color SDLtextColor = {(uint8_t) textColor.r,
                              (uint8_t) textColor.g,
                              (uint8_t) textColor.b,
                              (uint8_t) textColor.a };
    SDL_Rect dest;

    if (win == nullptr) {
        throw ArcadeExceptions("Unexpected error was caugth");
    }
    this->_win = win;
    this->id = id;
    this->type = Arcade::ECS::CompType::SDLTEXT;
    this->_font = TTF_OpenFont(path.data(), 24);
    if (this->_font == nullptr) {
        throw ArcadeExceptions("Wrong path for sprite : " + path);
    }
    surface = TTF_RenderText_Solid(this->_font, text.data(), SDLtextColor);
    if (surface == nullptr) {
        TTF_CloseFont(this->_font);
        throw ArcadeExceptions("Unable to load surface");
    }
    this->_text = SDL_CreateTextureFromSurface(this->_win, surface);
    if (this->_text == nullptr) {
        SDL_FreeSurface(surface);
        throw ArcadeExceptions("Unable to load texture");
    }
    dest.x = pos.x;
    dest.y = pos.y;
    dest.w = surface->w;
    dest.h = surface->h;
    this->_rect = dest;
    SDL_RenderCopy(this->_win, this->_text, NULL, &dest);
    SDL_FreeSurface(surface);
}

Arcade::SDL::SDLText::~SDLText()
{
    TTF_CloseFont(this->_font);
    SDL_DestroyTexture(this->_text);
}
