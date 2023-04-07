/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Text
*/

#pragma once

#include <memory>
#include <string>
#include <map>
#include "ISystem.hpp"
#include "Text.hpp"

namespace Ncurses {
    namespace System {
        class TextSystem : public Arcade::ECS::ISystem {
            public:
                TextSystem(std::map<std::string, short> &colorsUsed);
                void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &entityManager) final;

            private:
                bool printText(std::shared_ptr<Arcade::Graph::Text> text);
                short getColorPair(short fr, short fg, short fb, short br, short bg, short bb);
                std::map<std::string, short> &_colorsUsed;
        };
    }
}
