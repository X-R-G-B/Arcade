/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SceneManager
*/

#pragma once

#include "ISceneManager.hpp"

namespace Arcade {
    namespace Game {
        class SceneManager : public ISceneManager {
            public:
                SceneManager();
                ~SceneManager();

                void registerScene(const std::string &sceneName,
                std::unique_ptr<IScene> scene);

                std::unique_ptr<IScene> &getCurrentScene();

                void changeScene(const std::string &sceneName);
            protected:
            private:
                std::string _CurrentScene;
                std::map<const std::string, std::unique_ptr<IScene>> _Scenes;
        };
    }
}
