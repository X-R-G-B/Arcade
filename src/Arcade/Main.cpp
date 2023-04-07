/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** main
*/

#include <exception>
#include <iostream>
#include <string>
#include "Core.hpp"

void launchCore(int ac, char **av)
{
    std::unique_ptr<Arcade::Core::Core> core = nullptr;
    std::string str;

    str = (ac != 2) ? "" : av[1];
    try {
        core = std::make_unique<Arcade::Core::Core>(str);
    } catch (const std::exception &e) {
        throw;
    }
    core->update();
}

bool checkHelp(int ac, char **av)
{
    std::string str;

    if (ac != 2) {
        return false;
    }
    str = av[1];
    if (str == "-h" || str == "--help") {
        return true;
    }
    return false;
}

void printHelp()
{
    std::cout << "USAGE: " << std::endl;
    std::cout << "\t./arcade [-h | --help]" << std::endl;
    std::cout << "\t./arcade" << std::endl;
    std::cout << "\t./arcade [lib/arcade_sfml.so | lib/arcade_sdl2.so | lib/arcade_ncurses.so]" << std::endl;
    std::cout << "DESCRIPTION: " << std::endl;
    std::cout << "\tThe arcade game." << std::endl;
}

int main(int ac, char **av)
{
    if (checkHelp(ac, av)) {
        printHelp();
        return 0;
    }
    if (ac > 2) {
        return 84;
    }
    try {
        launchCore(ac, av);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
