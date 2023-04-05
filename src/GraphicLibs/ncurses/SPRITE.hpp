/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sprite
*/

#pragma once

#include <memory>
#include <string>
#include <map>
#include "ISystem.hpp"
#include "Sprite.hpp"

namespace Ncurses {
    namespace System {

        class SpriteSystem : public Arcade::ECS::ISystem {
            public:
                SpriteSystem(std::map<std::string, short> &colorsUsed);
                void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &entityManager) final;

            private:
                bool printText(std::shared_ptr<Arcade::Graph::Sprite> sprite);
                short getColorPair(short fr, short fg, short fb, short br, short bg, short bb);
                std::map<std::string, short> &_colorsUsed;
        };
    }
}
