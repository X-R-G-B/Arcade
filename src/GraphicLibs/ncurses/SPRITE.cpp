/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sprite
*/

#include <curses.h>
#include <memory>
#include "NcursesCompType.hpp"
#include "Sprite.hpp"
#include "SPRITE.hpp"
#include "Ncurses.hpp"

Ncurses::System::SpriteSystem::SpriteSystem(std::map<std::string, short> &colorsUsed)
    : _colorsUsed(colorsUsed)
{
}

short Ncurses::System::SpriteSystem::getColorPair(short fr, short fg, short fb, short br, short bg, short bb)
{
    std::string hash = std::to_string(fr) + " " + std::to_string(fg) + " " + std::to_string(fb) + " " + std::to_string(br) + " " + std::to_string(bg) + " " + std::to_string(bb);
    auto it = _colorsUsed.find(hash);
    if (it != _colorsUsed.end()) {
        return it->second;
    }
    short colorPair = 8;
    for (auto &[key, value] : _colorsUsed) {
        if (colorPair <= value) {
            colorPair = value + 3;
        }
    }
    _colorsUsed[hash] = colorPair;
    init_color(colorPair + 1, fr, fg, fb);
    init_color(colorPair + 2, br, bg, bb);
    init_pair(colorPair, colorPair + 1, colorPair + 2);
    return colorPair;
}

bool Ncurses::System::SpriteSystem::printText(const std::shared_ptr<Arcade::Graph::Sprite> sprite)
{
    int x = DisplayModule::getXFromX1920(sprite->pos.x);
    int y = DisplayModule::getYFromY1080(sprite->pos.y);
    short colorPair = 0;

    if (has_colors()) {
         colorPair = getColorPair(sprite->ttyData.foreground.r, sprite->ttyData.foreground.g, sprite->ttyData.foreground.b,
            sprite->ttyData.background.r, sprite->ttyData.background.g, sprite->ttyData.background.b);
        attron(COLOR_PAIR(colorPair));
    }
    for (auto &c : sprite->ttyData.defaultChar) {
        if (c == '\n') {
            y++;
            x = DisplayModule::getXFromX1920(sprite->pos.x);
        } else if (c == ' ') {
            x++;
        } else {
            mvaddch(y, x, c);
            x++;
        }
    }
    if (has_colors()) {
        attroff(COLOR_PAIR(colorPair));
    }
    return true;
}

void Ncurses::System::SpriteSystem::run(double deltaTime, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager)
{
    std::unique_ptr<std::vector<std::shared_ptr<Arcade::ECS::IComponent>>> sprite;

    try {
        sprite = entityManager.getComponentsByComponentType(Arcade::ECS::CompType::SPRITE);
    } catch (const std::exception &e) {
        return;
    }
    if (sprite.get() == nullptr) {
        return;
    }
    for (const auto &comp : *sprite) {
        const auto spriteComp = std::static_pointer_cast<Arcade::Graph::Sprite>(comp);
        this->printText(spriteComp);
    }
}
