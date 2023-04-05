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

static const short foregroundColor = 12;
static const short backgroundColor = 13;
static const short colorPair = 14;

bool Ncurses::System::SpriteSystem::printText(const std::shared_ptr<Arcade::Graph::Sprite> sprite)
{
    int x = DisplayModule::getXFromX1920(sprite->pos.x);
    int y = DisplayModule::getYFromY1080(sprite->pos.y);

    if (has_colors()) {
        init_color(foregroundColor, sprite->ttyData.foreground.r, sprite->ttyData.foreground.g, sprite->ttyData.foreground.b);
        init_color(backgroundColor, sprite->ttyData.background.r, sprite->ttyData.background.g, sprite->ttyData.background.b);
        init_pair(colorPair, foregroundColor, backgroundColor);
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
    auto texts = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::SPRITE);

    for (const auto &entity : *texts) {
        auto textComponents = entity->getComponents(Arcade::ECS::CompType::SPRITE);
        for (const auto &textComponent : textComponents) {
            const auto text = std::static_pointer_cast<Arcade::Graph::Sprite>(textComponent);
            this->printText(text);
        }
    }
}
