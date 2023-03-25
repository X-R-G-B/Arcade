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
#include <type_traits>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

template<typename resType>
class LibHandler {
    public:
        LibHandler(const std::string &) : _lib(nullptr), _module(nullptr), _type(std::nullopt)
        {
            loadLib(lib);
            if (std::is_same(resType, Arcade::Graph::IDisplayModule)) {
                getType
            }
            getType();
            _module = loadFunction<resType>("");
        }
        ~LibHandler();
        void loadLib(const std::string &);
        void deleteLib();
        const std::string getName()
        {
            return loadFunction<std::string>("getName");
        }
        const LibType getType()
        {
            if (_type == std::nullopt) {
                _type = loadFunction<LibType>("getType");
            }
            return _type;
        }
        const resType getModule()
        {
            if (_module) {
                deleteLib();
                _module = nullptr;
            }
            if (type == LibType::GAME) {
                _module = loadFunction<resType>("");
            } else {
                _module = loadFunction
            }
            return _module;
        }
        void callDestroyFunction()
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
            func(arg);
        }
        
        resType *loadFunction(const std::string &function)
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
        resType *_module;
        std::optional<LibType> _type;
        std::string _name;
};
