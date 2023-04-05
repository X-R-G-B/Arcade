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
    std::unique_ptr<Arcade::Core::Core> core = nullptr;
    std::string str;

    if (ac == 2) {
        str = av[1];
        core = std::make_unique<Arcade::Core::Core>(str);
    }
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
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
