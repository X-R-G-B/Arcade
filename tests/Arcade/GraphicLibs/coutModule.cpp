/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** coutModule
*/

#include "coutModule.hpp"

Arcade::Graph::CoutModule::CoutModule()
{
    std::cout << "Builded CoutModule" << std::endl;
    this->systemManager.addSystem("ouiSystem", std::make_unique<ouiSystem>());
}

Arcade::Graph::CoutModule::~CoutModule()
{
    std::cout << "Destruction CoutModule" << std::endl;
}

void Arcade::Graph::CoutModule::update(float delta,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &entityManager)
{

}

class ouiSystem : public ISystem {
    public :
        ouiSystem();
        ~ouiSystem();

        void run(float deltaTime,
        Arcade::ECS::IEventManager &eventManager,
        Arcade::ECS::IEntityManager &entityManager)
}

ouiSystem::ouiSystem()
{
    std::cout << "Creating system" << std::endl;
}

ouiSystem::~ouiSystem()
{
    std::cout << "Destroying system" << std::endl;
}

ouiSystem::run(float deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &entityManager)
{
    auto sprite = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::SPRITE);

    for (auto &it : sprite) {
        std::cout << sprite.id << std::endl;
    }
    std::cout << "Running system ouiSystem" << std::endl;
}
