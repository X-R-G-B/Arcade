/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** ASceneManager
*/

#pragma once

#include "ISceneManager.hpp"

namespace Arcade {
    namespace Game {
        class ASceneManager {
            public:
                ASceneManager();
                ~ASceneManager();

                void registerScene(const std::string &sceneName,
                std::unique_ptr<IScene> scene);

                std::unique_ptr<IScene> &getCurrentScene();

                void changeScene(const std::string &sceneName);
            protected:
            private:
                std::unique_ptr<IScene> _CurrentScene;
                // TODO attribute to stock all the map
        };
    }
}