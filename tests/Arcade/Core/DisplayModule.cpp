//replace main by this to test
//display module code

#include <iostream>
#include "DisplayModule.hpp"
#include "Sprite.hpp"

#define FALSE(x) std::cerr << "FALSE: " << x << std::endl; return 84;

int main(int ac, char **)
{
    std::vector<std::string> v;
    v.push_back("fst");
    v.push_back("scd");
    v.push_back("trd");
    std::unique_ptr<Arcade::Core::IDisplayModule> displayModule = std::make_unique<Arcade::Core::DisplayModule>(v);
    displayModule->changeGraphicLib();
    displayModule->changeGraphicLib("trd");
    displayModule->changeGraphicLib();
    displayModule->changeGraphicLib();


    displayModule->addComponent(std::make_unique<Comp>(Arcade::ECS::CompType::SOMETHING, "comp1"));

    try {
        displayModule->addComponent(std::make_unique<Comp>(Arcade::ECS::CompType::SOMETHING, "comp1"));
        FALSE("displayModule->addComponent(std::make_unique<Comp>(Arcade::ECS::CompType::SOMETHING));");
    } catch (const std::exception &e) {
    }
    auto components = displayModule->getComponents();
    if (components.size() != 1) {
        FALSE("components.size() != 2");
    }
    auto components2 = displayModule->getComponents(Arcade::ECS::CompType::SOMETHING);
    if (components.size() != 1) {
        FALSE("components.size() != 1");
    }
    auto components3 = displayModule->getComponents(Arcade::ECS::CompType::NOTHING);
    if (components.size() != 0) {
        FALSE("components.size() != 0");
    }
    displayModule->addComponent(std::make_unique<Comp>(Arcade::ECS::CompType::SOMETHING, "comp2"));
    displayModule->removeComponents(Arcade::ECS::CompType::SOMETHING);
    auto components4 = displayModule->getComponents();
    if (components4.size() != 1) {
        FALSE("components4.size() != 1");
    }
    displayModule->addComponent(std::make_unique<Comp>(Arcade::ECS::CompType::SOMETHING, "comp3"));
    displayModule->addComponent(std::make_unique<Comp>(Arcade::ECS::CompType::OTHERTHING, "comp4"));
    displayModule->removeComponent("Comp");
    if (displayModule->getComponents().size() != 0) {
        FALSE("displayModule->getComponents().size() != 0");
    }
    return 0;
}
