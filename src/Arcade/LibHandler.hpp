/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** LibHandler class
*/

#pragma once

#include <string>
#include <dlfcn.h>
#include <functional>
#include <stdexcept>

class LibHandler {
    public:
        LibHandler();
        LibHandler(const std::string &);
        ~LibHandler();
        void loadLib(const std::string &);
        void deleteLib();
        template<typename resType> resType loadDestroyFunction(const std::string &function, resType arg)
        {
            typedef void (*retType_t)(resType);
            retType_t func = NULL;

            if (_lib == nullptr) {
                throw std::runtime_error("No library loaded");
            }
            func = (retType_t) dlsym(_lib, function.c_str());
            if (!func) {
                throw std::invalid_argument("A library in lib/ don't respect entry points doc");
            }
            return func(arg);
        }
        template<typename resType> resType loadFunction(const std::string &function)
        {
            typedef resType (*retType_t)();
            retType_t func = NULL;

            if (_lib == nullptr) {
                throw std::runtime_error("No library loaded");
            }
            func = (retType_t) dlsym(_lib, function.c_str());
            if (!func) {
                throw std::invalid_argument("A library in lib/ don't respect entry points doc");
            }
            return func();
        }
    private:
        void *_lib;
};
