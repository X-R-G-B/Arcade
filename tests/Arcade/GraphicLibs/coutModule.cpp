/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** coutModule
*/

#include "coutModule.hpp"
#include "CompType.hpp"

Arcade::Graph::CoutModule::CoutModule()
{
    std::cout << "Builded CoutModule" << std::endl;
    this->_systemManager.addSystem("ouiSystem", std::make_unique<ouiSystem>());
}

Arcade::Graph::CoutModule::~CoutModule()
{
    std::cout << "Destruction CoutModule" << std::endl;
}

void Arcade::Graph::CoutModule::update(float delta,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &entityManager)
{
    _systemManager.update(delta, eventManager, entityManager);
}

Arcade::Graph::ouiSystem::ouiSystem()
{
    std::cout << "Creating system" << std::endl;
}

Arcade::Graph::ouiSystem::~ouiSystem()
{
    std::cout << "Destroying system" << std::endl;
}

void Arcade::Graph::ouiSystem::run(float deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &entityManager)
{
    auto sprite = entityManager.getComponentsByComponentType(Arcade::ECS::CompType::SPRITE);

    for (auto &it : *(sprite.get())) {
        std::cout << (*it.get()).id << std::endl;
    }
}
