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
    Arcade::Core::Core core = Arcade::Core::Core();
    std::string str;

    if (ac == 2) {
        str = av[1];
        core.loadGraphicLibFromPath(str);
    }
    core.update();
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
