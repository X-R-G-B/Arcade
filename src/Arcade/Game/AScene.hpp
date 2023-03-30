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
                AScene(std::unique_ptr<Arcade::ECS::IEntityManager> enitityManager);
                ~AScene() = default;

                ECS::IEntityManager &getEntityManager() final;
            protected:
                std::unique_ptr<ECS::IEntityManager> _EntityManager;
        };
    }
}
