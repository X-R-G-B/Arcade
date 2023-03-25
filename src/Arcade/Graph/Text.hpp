/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Text
*/

#pragma once

#include "IText.hpp"
#include "AComponent.hpp"

namespace Arcade {
    namespace Graph {
        struct Text : public IText {
            public :
                Text(std::string id);
        };
    }
}
