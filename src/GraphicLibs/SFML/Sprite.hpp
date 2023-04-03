/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml
*/

#include "IComponent.hpp"
#include "ISystem.hpp"
#include "GraphStruct.hpp"
#include "ISprite.hpp"
#include "Sfml.hpp"

namespace Arcade {

    namespace Sfml {

        class SpriteSystem : public ECS::ISystem {
            public:
                SpriteSystem(sf::RenderWindow &win);
                void run(float deltaTime,
                    ECS::IEventManager &eventManager,
                    ECS::IEntityManager &entityManager) final;
            private:
                sf::RenderWindow &_win;
                void handleComponent(ECS::IComponent &comp, ECS::IEntity &entity);

        };

        struct SfSprite : public ECS::IComponent {
            public:
                SfSprite(const std::string id, const std::string &path,
                    const Arcade::Vector3f &pos, Graph::Rect &rect, sf::RenderWindow &win);
                sf::RenderWindow &_win;
                sf::Sprite sprite;
        };
    }
}
