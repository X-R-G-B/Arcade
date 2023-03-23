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

                bool init() override;
                void close() override;

                ECS::IEntityManager &getEntityManager() final;
                ECS::ISystemManager &getSystemManager() final;
            protected:
            private:
                ECS::ISystemManager &_SystemManager;
                ECS::IEntityManager &_EntityManager;
        };
    }
}
