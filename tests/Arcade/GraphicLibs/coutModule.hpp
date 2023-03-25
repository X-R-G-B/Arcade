/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** coutModule
*/

#pragma once

#include "../../../src/Arcade/Core/IDisplayModule.hpp"

namespace Arcade {
    namespace Graph {
        class CoutModule : public Core::IDisplayModule {
            public :
                CoutModule();
                ~CoutModule();

                void update(float delta,
                ECS::IEventManager &eventManager,
                ECS::IEntityManager &entityManager);
            protected :
            private :
                ECS::SystemManager systemManager;
        };
    }
}