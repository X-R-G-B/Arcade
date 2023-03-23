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
    std::unique_ptr<Arcade::Core::Core> core = std::make_unique<Arcade::Core::Core>();
    std::string str;

    if (ac == 2) {
        str = av[1];
        core->loadGraphicLibFromPath(str);
    }
    core->update();
}
#include "GameModule.hpp"    
int main(int ac, char **)
{
    std::vector<std::string> v;
    v.push_back("nibleur");
    v.push_back("snake");
    std::unique_ptr<Arcade::Core::IGameModule> gameModule = std::make_unique<Arcade::Core::GameModule>(v);
    std::cout << gameModule->isGameLoaded() << std::endl;
    std::cout << gameModule->getSceneManager().get() << std::endl;
    gameModule->changeGame();
    std::cout << gameModule->isGameLoaded() << std::endl;
    std::cout << gameModule->getSceneManager().get() << std::endl;
    gameModule->changeGame("snake");
    std::cout << gameModule->getSceneManager().get() << std::endl;
    std::vector<std::string> vres = gameModule->getGamesNames();
    std::cout << vres.front();
}

//int main(int ac, char **av)
//{
//    if (ac > 2) {
//        return 84;
//    }
//    try {
//        launchCore(ac, av);
//    } catch (std::exception &e) {
//        std::cout << e.what() << std::endl;
//        return 84;
//    }
//}
//