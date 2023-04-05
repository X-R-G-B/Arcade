/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** MainMenuModule
*/

#include "Api2.hpp"
#include "IMainMenuModule.hpp"
#include "MainMenuModule.hpp"

extern "C" {
    const char *getName()
    {
        return "Basic Main Menu";
    }

    LibType getType()
    {
        return LibType::MENU;
    }

    Arcade::MainMenu::IMainMenuModule *getMainMenuModule(Arcade::MainMenu::Context *context)
    {
        return new BasicMenu::MainMenuModule(context);
    }

    void destroyMainMenuModule(Arcade::MainMenu::IMainMenuModule *mod)
    {
        delete mod;
    }
}
