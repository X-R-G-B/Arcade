/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EntryPoint
*/

#include "Nibbler.hpp"
#include <memory>
#include "Api.hpp"
#include "AppleSystem.hpp"
#include "AutoTurnSystem.hpp"
#include "CheckDisappearingBodies.hpp"
#include "EatSystem.hpp"
#include "GameScene.hpp"
#include "HeadCollision.hpp"
#include "InputsSystem.hpp"
#include "MoveDirection.hpp"
#include "MoveForward.hpp"
#include "MoveInput.hpp"
#include "NibblerCompType.hpp"
#include "Restart.hpp"
#include "SnakeGrowSystem.hpp"

extern "C" {
    LibType getType()
    {
        return LibType::GAME;
    }

    const char *getName()
    {
        return "Nibbler";
    }

    Arcade::Game::IGameModule *getGameModule()
    {
        return new Nibbler::NibblerGameModule();
    }

    void destroyGameModule(Arcade::Game::IGameModule *gameModule)
    {
        delete gameModule;
    }
}

Nibbler::NibblerGameModule::NibblerGameModule()
{
    _scenes.push_back(std::make_unique<Nibbler::Scene::GameScene>());
    _scenes.front()->init();
    _systemManager.addSystem("AMoveInput", std::make_unique<Nibbler::System::MoveInput>());
    _systemManager.addSystem("InputsSystem", std::make_unique<Nibbler::System::InputsSystem>());
    _systemManager.addSystem("MoveForward", std::make_unique<Nibbler::System::MoveForward>());
    _systemManager.addSystem("MoveDirection", std::make_unique<Nibbler::System::MoveDirection>());
    _systemManager.addSystem("Restart", std::make_unique<Nibbler::System::Restart>(_scenes.front()));
    _systemManager.addSystem("AAcollisionSystem", std::make_unique<Nibbler::System::HeadCollision>());
    _systemManager.addSystem("AppleGeneration", std::make_unique<Nibbler::System::AppleSystem>());
    _systemManager.addSystem("EatSystem", std::make_unique<Nibbler::System::EatSystem>());
    _systemManager.addSystem("AAGrowSystem", std::make_unique<Nibbler::System::SnakeGrowSystem>());
//    _systemManager.addSystem("ZScoreSystem", std::make_unique<Nibbler::System::Score>());
    _systemManager.addSystem("CheckDisappearingBodies", std::make_unique<Nibbler::System::CheckDisappearingBodies>());
    _systemManager.addSystem("ZAutoTurnSystem", std::make_unique<Nibbler::System::AutoTurnSystem>());
}

Arcade::ECS::IEntityManager &Nibbler::NibblerGameModule::getCurrentEntityManager()
{
    return _scenes.front()->getEntityManager();
}

void Nibbler::NibblerGameModule::update(double deltaTime, Arcade::ECS::IEventManager &eventManager)
{
    _systemManager.update(deltaTime, eventManager, getCurrentEntityManager());
}
