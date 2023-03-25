/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** coutModule
*/

#pragma once

#include <iostream>
#include "IDisplayModule.hpp"
#include "SystemManager.hpp"

namespace Arcade {
    namespace Graph {

        class ouiSystem : public ECS::ISystem {
            public:
                ouiSystem();
                ~ouiSystem();
                void run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &entityManager);
        };

        class CoutModule : public Graph::IDisplayModule {
            public:
                CoutModule();
                ~CoutModule();

                void update(float delta,
                ECS::IEventManager &eventManager,
                ECS::IEntityManager &entityManager);
            private:
                ECS::SystemManager _systemManager;
        };
    }
}