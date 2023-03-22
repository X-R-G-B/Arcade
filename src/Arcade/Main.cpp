/*
** EPITECH PROJECT, 2023
** Archi Arcade Promo 2026 Toulouse
** File description:
** GameModule that will be passed to all systems, implemented in the core (it
** contains the Scene Manager created in the game lib)
*/

#include <exception>
#include "Core.hpp"

void launchCore(int ac, char **av)
{
    std::unique_ptr<Arcade::Core::Core> core = std::make_unique<Arcade::Core::Core>();
    std::string str;

    if (ac == 2) {
        str = av[1];
        core->loadGraphicLibFromPath(str);
    }
    //core.update();
    //TODO uncomment when update is emplemented
}

int main(int ac, char **av)
{
    if (ac > 2) {
        return 84;
    }
    try {
        launchCore(ac, av);
    } catch (std::exception &e) {
        return 84;
    }
}
