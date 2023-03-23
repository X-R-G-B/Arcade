/*
** EPITECH PROJECT, 2023
** Archi Arcade Promo 2026 Toulouse
** File description:
** GameModule that will be passed to all systems, implemented in the core (it
** contains the Scene Manager created in the game lib)
*/

#pragma once

#include "IGameModule.hpp"

namespace Arcade {
    namespace Core {
        class GameModule : public IGameModule {
            public:
                Arcade::Game::ISceneManager &getSceneManager() final;
                void changeGame(const std::string &gameName) final;
                void changeGame() final;
            private:

        };
    }
}
