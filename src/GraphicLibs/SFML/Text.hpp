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

namespace Arcade {

    namespace Sfml {

        enum class CompType : int {
            Text = 0,
            SPRITE = 1,
            MUSIC = 2,
            SfmlWindow = 3,
            SfmlText = 4
        };

        class TextSystem : public ECS::ISystem {
            public:
                void run(float deltaTime,
                    ECS::IEventManager &eventManager,
                    ECS::IEntityManager &entityManager) final;
            private:
                void handleComponent(ECS::IComponent &comp, ECS::IEntity &entity);
        };

        class Text : public ECS::IComponent {
            public:
                SfmlText(const std::string id, const std::string &path,
                    const std::string &text, const Graph::Color &textColor,
                    const Arcade::Vector3f &pos);
            private:
                sf::Text text;
        };
    }
}
