/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Ncurses
*/

#include <curses.h>
#include <memory>
#include "Ncurses.hpp"
#include "Sprite.hpp"
#include "TEXT.hpp"
#include "SPRITE.hpp"
#include "MUSIC.hpp"
#include "EVENTS.hpp"
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
    if (has_colors()) {
        start_color();
    }
    noecho();
    cbreak();
    raw();
    nodelay(stdscr, TRUE);
    notimeout(stdscr, TRUE);
    keypad(stdscr, TRUE);
    _systems.addSystem("Text", std::make_unique<Ncurses::System::TextSystem>(_colorsUsed));
    _systems.addSystem("Sprite", std::make_unique<Ncurses::System::SpriteSystem>(_colorsUsed));
    _systems.addSystem("Music", std::make_unique<Ncurses::System::MusicSystem>());
    _systems.addSystem("Events", std::make_unique<Ncurses::System::EventsSystem>());
    auto &entity = _entityManager.createEntity("No Place to display");
    auto textComp = std::make_shared<Arcade::Graph::Text>("Resize");
    textComp->text = "Please allow more space to this terminal";
    textComp->pos = {0, 0, 0};
    textComp->textColor = {255, 255, 255, 255};
    textComp->backgroundColor = {0, 0, 0, 0};
    entity.addComponent(textComp);
}

Ncurses::DisplayModule::~DisplayModule()
{
    endwin();
}

void Ncurses::DisplayModule::update(double delta, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager)
{
    _frames += delta;
    if (_frames < 16.66666) {
        return;
    }
    clear();
    _frames -= 16.66666;
    if (COLS < 240 || LINES < 67) {
        _systems.update(delta, eventManager, _entityManager);
    } else {
        _systems.update(delta, eventManager, entityManager);
    }
    refresh();
    _colorsUsed.clear();
}

/*
   1920 | 240
   x    | ?
*/
int Ncurses::DisplayModule::getXFromX1920(int x)
{
    return x * 240 / 1920;
}

/*
   1080 | 67
   x    | ?
*/
int Ncurses::DisplayModule::getYFromY1080(int y)
{
    return y * 67 / 1080;
}
