/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFML_Music
*/

#pragma once

#include "ISystem.hpp"

class SFML_Music : public Arcade::ECS::ISystem {
    public:
        SFML_Music() = default;
        ~SFML_Music() = default;

        void run(std::size_t deltaTime, Arcade::ECS::IEventManager &,
        Arcade::Core::IDisplayModule &displayModule,
        Arcade::Core::IGameModule &gameModule) override; // wtf, it is not an override, not the same parameters

    protected:
    private:
};
