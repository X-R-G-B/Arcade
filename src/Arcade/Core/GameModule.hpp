/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** GameModule header
*/

#pragma once

#include "IGameModule.hpp"

namespace Arcade {
    namespace Core {
        class GameModule : public IGameModule {
            public:
                GameModule(std::vector<std::string> libsNames);
                std::unique_ptr<Arcade::Game::ISceneManager> &getSceneManager() final;
                void changeGame(const std::string &gameName) final;
                void changeGame() final;
                std::vector<std::string> getGamesNames() final;
                bool isGameLoaded() final;
            private:
                void loadGame(const std::string &gameName);
                std::unique_ptr<Arcade::Game::ISceneManager> _sceneManager;
                std::vector<std::string> _libsNames;
                std::string _currentLib;
        };
    }
}
