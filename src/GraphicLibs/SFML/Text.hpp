/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Text
*/

#pragma once

#include "IComponent.hpp"
#include "ISystem.hpp"
#include "GraphStruct.hpp"
#include "IText.hpp"
#include "Sfml.hpp"

namespace Arcade {

    namespace Sfml {

        class TextSystem : public ECS::ISystem {
            public:
                TextSystem(sf::RenderWindow &win);
                void run(float deltaTime,
                    ECS::IEventManager &eventManager,
                    ECS::IEntityManager &entityManager) final;
            private:
                sf::RenderWindow &_win;
                void handleComponent(ECS::IComponent &comp, ECS::IEntity &entity);

        };

        struct SfText : public ECS::IComponent {
            public:
                SfText(const std::string id, const std::string &path,
                    const std::string &text, const Graph::Color &textColor,
                    const Arcade::Vector3f &pos, sf::RenderWindow &win);
                sf::RenderWindow &_win;
                sf::Font font;
                sf::Text text;
        };
    }
}
