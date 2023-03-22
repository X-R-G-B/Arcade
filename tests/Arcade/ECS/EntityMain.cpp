/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EntityMain
*/

#include <iostream>
#include "Entity.hpp"

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

    entity.addComponent(std::make_unique<Comp>(Arcade::ECS::CompType::SOMETHING, "comp1"));

    try {
        entity.addComponent(std::make_unique<Comp>(Arcade::ECS::CompType::SOMETHING, "comp1"));
        FALSE("entity.addComponent(std::make_unique<Comp>(Arcade::ECS::CompType::SOMETHING));");
    } catch (const std::exception &e) {
    }
    auto components = entity.getComponents();
    if (components.size() != 1) {
        FALSE("components.size() != 2");
    }
    auto components2 = entity.getComponents(Arcade::ECS::CompType::SOMETHING);
    if (components.size() != 1) {
        FALSE("components.size() != 1");
    }
    auto components3 = entity.getComponents(Arcade::ECS::CompType::NOTHING);
    if (components.size() != 0) {
        FALSE("components.size() != 0");
    }
    entity.addComponent(std::make_unique<Comp>(Arcade::ECS::CompType::SOMETHING, "comp2"));
    entity.removeComponents(Arcade::ECS::CompType::SOMETHING);
    auto components4 = entity.getComponents();
    if (components4.size() != 1) {
        FALSE("components4.size() != 1");
    }
    entity.addComponent(std::make_unique<Comp>(Arcade::ECS::CompType::SOMETHING, "comp3"));
    entity.addComponent(std::make_unique<Comp>(Arcade::ECS::CompType::OTHERTHING, "comp4"));
    entity.removeComponent("Comp");
    if (entity.getComponents().size() != 0) {
        FALSE("entity.getComponents().size() != 0");
    }
    return 0;
}