/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** main
*/

#include <exception>
#include <iostream>
#include "Core.hpp"

void launchCore(int ac, char **av)
{
    std::unique_ptr<Arcade::Core::Core> core;
    std::string str;

    if (ac == 2) {
        str = av[1];
    }
    core = std::make_unique<Arcade::Core::Core>(str);
    core->update();
}

int main(int ac, char **av)
{
    if (ac > 2) {
        return 84;
    }
    try {
        launchCore(ac, av);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 84;
    }
}

//#include <iostream>
//#include <memory>
//#include "DisplayModule.hpp"
//#include "Sprite.hpp"
//
//#define FALSE(x) std::cerr << "FALSE: " << x << std::endl; return 84;
//
//int main(int ac, char **)
//{
//    std::vector<std::string> v;
//    v.push_back("fst");
//    v.push_back("scd");
//    v.push_back("trd");
//    std::unique_ptr<Arcade::Core::IDisplayModule> displayModule = std::make_unique<Arcade::Core::DisplayModule>(v);
//    displayModule->changeGraphicLib();
//    displayModule->changeGraphicLib("trd");
//    displayModule->changeGraphicLib();
//    displayModule->changeGraphicLib();
//
//
//    displayModule->addComponent(std::make_unique<Arcade::Graph::Sprite>(Arcade::ECS::CompType::SPRITE, "comp1"));
//
//    try {
//        displayModule->addComponent(std::make_shared<Arcade::Graph::Sprite>(Arcade::ECS::CompType::SPRITE, "comp1"));
//        FALSE("displayModule->addComponent(std::make_unique<Arcade::Graph::Sprite>(Arcade::ECS::CompType::SPRITE));");
//    } catch (const std::exception &e) {
//    }
//    auto components = displayModule->getComponents();
//    if (components.size() != 1) {
//        FALSE("components.size() != 2");
//    }
//    auto components2 = displayModule->getComponents(Arcade::ECS::CompType::SPRITE);
//    if (components.size() != 1) {
//        FALSE("components.size() != 1");
//    }
//    auto components3 = displayModule->getComponents(Arcade::ECS::CompType::TEXT);
//    if (components.size() != 0) {
//        FALSE("components.size() != 0");
//    }
//    displayModule->addComponent(std::make_unique<Arcade::Graph::Sprite>(Arcade::ECS::CompType::SPRITE, "comp2"));
//    displayModule->removeComponents(Arcade::ECS::CompType::SPRITE);
//    auto components4 = displayModule->getComponents();
//    if (components4.size() != 1) {
//        FALSE("components4.size() != 1");
//    }
//    displayModule->addComponent(std::make_unique<Arcade::Graph::Sprite>(Arcade::ECS::CompType::SPRITE, "comp3"));
//    displayModule->addComponent(std::make_unique<Arcade::Graph::Sprite>(Arcade::ECS::CompType::MUSIC, "comp4"));
//    displayModule->removeComponent("Comp");
//    if (displayModule->getComponents().size() != 0) {
//        FALSE("displayModule->getComponents().size() != 0");
//    }
//    return 0;
//}
//