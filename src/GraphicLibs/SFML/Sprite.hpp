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

        struct SfSprite : public ECS::IComponent {
            public:
                SfSprite(const std::string id, const std::string &path,
                    const Arcade::Vector3f &pos, Graph::Rect &rect, sf::RenderWindow &win);
                sf::RenderWindow &_win;
                sf::Sprite sprite;
                sf::Texture texture;
        };

        class SpriteSystem : public ECS::ISystem {
            public:
                SpriteSystem(sf::RenderWindow &win, std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &components);
                void run(double deltaTime,
                    ECS::IEventManager &eventManager,
                    ECS::IEntityManager &entityManager) final;
            private:
                sf::RenderWindow &_win;
                std::vector<std::shared_ptr<ECS::IComponent>> &_components;
                std::shared_ptr<SfSprite> getComponent(std::shared_ptr<Graph::ISprite> SpriteComp);
                void handleComponent(std::shared_ptr<Graph::ISprite> SpriteComp);

        };
    }
}
