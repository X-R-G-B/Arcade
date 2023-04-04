/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Ncurses
*/

#include <curses.h>
#include <memory>
#include "Ncurses.hpp"
#include "TEXT.hpp"
#include "Api.hpp"

extern "C" {
    const char *getName(void)
    {
        return "Ncurses";
    }

    LibType getType(void)
    {
        return LibType::GRAPH;
    }

    Arcade::Graph::IDisplayModule *getDisplayModule(void)
    {
        return new Ncurses::DisplayModule();
    }

    void destroyDisplayModule(Arcade::Graph::IDisplayModule *displayModule)
    {
        delete displayModule;
    }
}

Ncurses::DisplayModule::DisplayModule(): _frames(0)
{
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    _systems.addSystem("Text", std::make_unique<Ncurses::System::TextSystem>());
}

Ncurses::DisplayModule::~DisplayModule()
{
    endwin();
}

void Ncurses::DisplayModule::update(float delta, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager)
{
    _frames += delta;
    if (delta > 16.66666) {
        _frames -= 16.66666;
    }
    _systems.update(delta, eventManager, entityManager);
}
