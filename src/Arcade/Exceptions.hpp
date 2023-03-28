/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Exceptions
*/

#pragma once

#include <string>
#include <exception>

class ArcadeExceptions : public std::exception {
    public:
        ArcadeExceptions(const std::string &message) : _message(message) {}
        const char *what() const noexcept override { return _message.c_str(); }
    private:
        std::string _message;
};
