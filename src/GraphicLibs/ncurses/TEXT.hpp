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
        struct RGB {
            unsigned char r;
            unsigned char g;
            unsigned char b;
        };

        class TextSystem : public Arcade::ECS::ISystem {
            public:
                void run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &entityManager) final;

            private:
                bool printText(std::shared_ptr<Arcade::Graph::Text> text);
        };
    }
}
