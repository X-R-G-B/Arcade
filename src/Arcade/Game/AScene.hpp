/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AScene
*/

#pragma once

#include "IScene.hpp"

namespace Arcade {
    namespace Game {
        class AScene : public IScene {
            public:
                AScene();
                ~AScene() = default;

                ECS::IEntityManager &getEntityManager();
            protected:
            private:
                std::unique_ptr<ECS::ISystemManager> _SystemManager;
                std::unique_ptr<ECS::IEntityManager> _EntityManager;
        };
    }
}
