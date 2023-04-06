/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EntryPoint
*/

#include <memory>
#include "Api.hpp"
#include "Nibbler.hpp"
//#include "MoveInput.hpp"
//#include "MoveForward.hpp"
#include "GameScene.hpp"
//#include "AppleSystem.hpp"
//#include "NibblerGrow.hpp"
#include "NibblerCompType.hpp"
//#include "Restart.hpp"
//#include "HeadCollision.hpp"
//#include "EatSystem.hpp"
//#include "NibblerGrowSystem.hpp"

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
//    _systemManager.addSystem("MoveInput", std::make_unique<Nibbler::System::MoveInput>());
//    _systemManager.addSystem("MoveForward", std::make_unique<Nibbler::System::MoveForward>());
//    _systemManager.addSystem("Restart", std::make_unique<Nibbler::System::Restart>(_scenes.front()));
//    _systemManager.addSystem("Apple", std::make_unique<Nibbler::System::AppleSystem>(_scenes.front()->getEntityManager()));
//    _systemManager.addSystem("collisionSystem", std::make_unique<Nibbler::System::HeadCollision>());
//    _systemManager.addSystem("EatSystem", std::make_unique<Nibbler::System::EatSystem>());
//    _systemManager.addSystem("GrowSystem", std::make_unique<Nibbler::System::NibblerGrowSystem>());
}

Arcade::ECS::IEntityManager &Nibbler::NibblerGameModule::getCurrentEntityManager()
{
    return _scenes.front()->getEntityManager();
}

void Nibbler::NibblerGameModule::update(double deltaTime, Arcade::ECS::IEventManager &eventManager)
{
    _systemManager.update(deltaTime, eventManager, getCurrentEntityManager());
}
