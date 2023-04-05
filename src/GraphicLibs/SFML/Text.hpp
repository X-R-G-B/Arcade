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

        struct SfText : public ECS::IComponent {
            public:
                SfText(const std::string id, const std::string &path,
                    const std::string &text, const Graph::Color &textColor,
                    const Arcade::Vector3f &pos, sf::RenderWindow &win);
                sf::RenderWindow &_win;
                sf::Font font;
                sf::Text text;
        };

        class TextSystem : public ECS::ISystem {
            public:
                TextSystem(sf::RenderWindow &win, std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &components);
                void run(double deltaTime,
                    ECS::IEventManager &eventManager,
                    ECS::IEntityManager &entityManager) final;
            private:
                sf::RenderWindow &_win;
                std::vector<std::shared_ptr<ECS::IComponent>> &_components;
                std::shared_ptr<SfText> getComponent(std::shared_ptr<Graph::IText> TextComp);
                void handleComponent(std::shared_ptr<Graph::IText> TextComp);

        };
    }
}
