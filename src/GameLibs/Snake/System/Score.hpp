/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Score
*/

#include "ISystem.hpp"
#include "IScene.hpp"

namespace Snake {
    namespace System {
        class Score : public Arcade::ECS::ISystem {
            public:
                void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentEntityManager) final;
            private:
                double _float = 0;
        };
    }
}
