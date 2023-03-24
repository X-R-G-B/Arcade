/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** GameModule header
*/

#pragma once

#include "IGameModule.hpp"
#include "Module.hpp"

namespace Arcade {
    namespace Core {
        class GameModule : public IGameModule, public Module {
            public:
                GameModule(std::vector<std::string> libsNames);
                std::shared_ptr<Arcade::Game::ISceneManager> getSceneManager() final;
                void changeGame(const std::string &gameName) final;
                void changeGame() final;
                std::vector<std::string> &getGamesNames();
            private:
                void loadGame(const std::string &gameName);
                std::shared_ptr<Arcade::Game::ISceneManager> _sceneManager;
        };
    }
}
