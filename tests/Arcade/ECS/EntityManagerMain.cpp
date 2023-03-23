/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EntityMain
*/

#include <iostream>
#include "Entity.hpp"
#include "EntityManager.hpp"

#define FALSE(x) std::cerr << "FALSE: " << x << std::endl; return 84;

namespace Arcade {
    namespace ECS {
        enum class CompType {
            SOMETHING,
            OTHERTHING,
            NOTHING
        };
    }
}

class Comp : public Arcade::ECS::IComponent {
    public:
        Comp(Arcade::ECS::CompType type, const std::string &id) {
            _id = id;
            _type = type;
        }
        ~Comp() = default;
        Arcade::ECS::CompType getType() const override {
            return _type;
        }
        const std::string &getId() const override {
            return _id;
        }
        std::string _id;
        Arcade::ECS::CompType _type;
};

int main()
{
    Arcade::ECS::Entity entity("entity");
    Arcade::ECS::EntityManager manager;

    entity.addComponent(std::make_unique<Comp>(Arcade::ECS::CompType::SOMETHING, "comp1"));
    entity.addComponent(std::make_unique<Comp>(Arcade::ECS::CompType::OTHERTHING, "comp2"));

    manager.createEntity("entity2");
    auto entities = manager.getEntities();
    if (entities.size() != 1)
        FALSE("getEntities() should return 1 entity");
    if (entities[0]->getId() != "entity2")
        FALSE("getEntities() should return entity2");
    manager.createEntity("entity3");
    entities = manager.getEntities();
    if (entities.size() != 2)
        FALSE("getEntities() should return 2 entities");
    if (entities[0]->getId() != "entity2")
        FALSE("getEntities() should return entity2");
    if (entities[1]->getId() != "entity3")
        FALSE("getEntities() should return entity3");
    auto entities2 = manager.getEntitiesByComponentType(Arcade::ECS::CompType::SOMETHING);
    if (entities2->size() != 1)
        FALSE("getEntitiesByComponentType() should return 1 entity");
    if (entities2->at(0)->getId() != "entity")
        FALSE("getEntitiesByComponentType() should return entity");
    manager.removeEntity("entity2");
    entities = manager.getEntities();
    if (entities.size() != 1)
        FALSE("getEntities() should return 1 entity");
    if (entities[0]->getId() != "entity3")
        FALSE("getEntities() should return entity3");
    manager.removeAllEntities();
    entities = manager.getEntities();
    if (entities.size() != 0)
        FALSE("getEntities() should return 0 entity");
    return 0;
}
