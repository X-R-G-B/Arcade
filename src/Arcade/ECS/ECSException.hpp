/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EcsException
*/

#pragma once

#include <exception>
#include <string>

namespace Arcade {
    namespace ECS {
        class ECSException : public std::exception {
            public:
                ECSException(const std::string &message) : _message(message) {}
                const char *what() const noexcept override { return _message.c_str(); }
            private:
                std::string _message;
        };
    }
}