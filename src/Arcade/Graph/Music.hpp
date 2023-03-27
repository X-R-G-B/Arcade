/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Music
*/

#pragma once

#include "IMusic.hpp"

namespace Arcade {
    namespace Graph {
        class Music : public IMusic {
            public:
                Music(const std::string &id);
        };
    }
}

