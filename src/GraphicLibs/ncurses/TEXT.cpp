/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Text
*/

#include <curses.h>
#include <memory>
#include <ncurses.h>
#include "NcursesCompType.hpp"
#include "Text.hpp"
#include "TEXT.hpp"
#include "Ncurses.hpp"
#include <iostream>

static const short foregroundColor = 9;
static const short backgroundColor = 10;
static const short colorPair = 11;

bool Ncurses::System::TextSystem::printText(const std::shared_ptr<Arcade::Graph::Text> text)
{
    int x = DisplayModule::getXFromX1920(text->pos.x);
    std::cerr << "x: " << x << std::endl;
    int y = DisplayModule::getYFromY1080(text->pos.y);
    std::cerr << "y: " << y << std::endl;

    init_color(foregroundColor, text->textColor.r, text->textColor.g, text->textColor.b);
    init_color(backgroundColor, text->backgroundColor.r, text->backgroundColor.g, text->backgroundColor.b);
    init_pair(colorPair, foregroundColor, backgroundColor);
    attron(colorPair);
    for (auto &c : text->text) {
        if (c == '\n') {
            y++;
            x = DisplayModule::getXFromX1920(text->pos.x);
        } else if (c == ' ') {
            x++;
        } else {
            mvaddch(y, x, c);
            x++;
        }
    }
    attroff(colorPair);
    return true;
}

void Ncurses::System::TextSystem::run(float deltaTime, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager)
{
    auto texts = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::TEXT);

    for (const auto &entity : *texts) {
        auto textComponents = entity->getComponents(Arcade::ECS::CompType::TEXT);
        for (const auto &textComponent : textComponents) {
            const auto text = std::static_pointer_cast<Arcade::Graph::Text>(textComponent);
            this->printText(text);
        }
    }
}
