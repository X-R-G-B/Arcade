/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Text
*/

#include <curses.h>
#include <memory>
#include "NcursesCompType.hpp"
#include "Text.hpp"
#include "TEXT.hpp"
#include "Ncurses.hpp"

Ncurses::System::TextSystem::TextSystem(std::map<std::string, short> &colorsUsed)
    : _colorsUsed(colorsUsed)
{
}

short Ncurses::System::TextSystem::getColorPair(short fr, short fg, short fb, short br, short bg, short bb)
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

bool Ncurses::System::TextSystem::printText(const std::shared_ptr<Arcade::Graph::Text> text)
{
    int x = DisplayModule::getXFromX1920(text->pos.x);
    int y = DisplayModule::getYFromY1080(text->pos.y);
    short colorPair = 0;

    if (has_colors()) {
         colorPair = getColorPair(text->textColor.r, text->textColor.g, text->textColor.b,
            text->backgroundColor.r, text->backgroundColor.g, text->backgroundColor.b);
        attron(COLOR_PAIR(colorPair));
    }
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
    if (has_colors()) {
        attroff(COLOR_PAIR(colorPair));
    }
    return true;
}

void Ncurses::System::TextSystem::run(double deltaTime, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager)
{
    std::unique_ptr<std::vector<std::shared_ptr<Arcade::ECS::IComponent>>> texts;

    try {
        texts = entityManager.getComponentsByComponentType(Arcade::ECS::CompType::TEXT);
    } catch (const std::exception &e) {
        return;
    }
    if (texts.get() == nullptr) {
        return;
    }
    for (const auto &comp : *texts) {
        const auto text = std::static_pointer_cast<Arcade::Graph::Text>(comp);
        this->printText(text);
    }
}
