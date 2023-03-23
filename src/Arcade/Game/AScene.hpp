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
                AScene(std::shared_ptr<ECS::ISystemManager> sysManager,
                    std::shared_ptr<ECS::IEntityManager> entManager);
                ~AScene() = default;

                const std::shared_ptr<ECS::IEntityManager> &getEntityManager() final;
                const std::shared_ptr<ECS::ISystemManager> &getSystemManager() final;
            protected:
            private:
                std::shared_ptr<ECS::ISystemManager> _SystemManager;
                std::shared_ptr<ECS::IEntityManager> _EntityManager;
        };
    }
}
