/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFML_EventHandler
*/

#include "ISystem.hpp"

namespace Nibbler {
    namespace System {
        class InputsSystem : public Arcade::ECS::ISystem {
            public:
                void run(double deltaTime,
                    Arcade::ECS::IEventManager &eventManager,
                    Arcade::ECS::IEntityManager &currentScene) final;
        };
    }
}
