/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Text
*/

#pragma once

#include <SFML/Graphics/Text.hpp>
#include "IComponent.hpp"
#include "ISystem.hpp"
#include "GraphStruct.hpp"
#include "IText.hpp"

namespace Arcade {

    namespace ECS {
        enum class CompType : int {
            TEXT = 0,
            SPRITE = 1,
            MUSIC = 2,
            WINDOW = 3,
            SFTEXT = 4
        };
    }

    namespace Sfml {

        class TextSystem : public ECS::ISystem {
            public:
                void run(float deltaTime,
                    ECS::IEventManager &eventManager,
                    ECS::IEntityManager &entityManager) final;
            private:
                void handleComponent(Graph::IText &comp, ECS::IEntity &entity);
        };

        class Text : public ECS::IComponent {
            public:
                Text(const std::string id, const std::string &path,
                    const std::string &text, const Graph::Color &textColor,
                    const Arcade::Vector3f &pos);
            private:
                sf::Text text;
        };
    }
}
