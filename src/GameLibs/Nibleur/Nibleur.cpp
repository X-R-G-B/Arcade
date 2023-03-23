#include "Api.hpp"

LibType getType()
{
    return LibType::GAME;
}

std::string getName()
{
    return "nibleur";
}

std::unique_ptr<Arcade::Game::ISceneManager> getScenes()
{
    return std::make_unique<Arcade::Game::ISceneManager>(nullptr);
}
