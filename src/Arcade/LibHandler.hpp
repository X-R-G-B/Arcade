/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** LibHandler class
*/

#pragma once

#include <iostream>
#include <string>
#include <dlfcn.h>
#include <functional>
#include <stdexcept>
#include <type_traits>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "Api.hpp"

template<typename T>
class LibHandler {
    public:
        LibHandler() : _lib(nullptr), _module(nullptr)
        {
            if (std::is_same<T, Arcade::Graph::IDisplayModule>::value) {
                _type = LibType::GRAPH;
                _funcCreator = "getDisplayModule";
                _funcDestructor = "destroyDisplayModule";
            } else if (std::is_same<T, Arcade::Game::IGameModule>::value) {
                _type = LibType::GAME;
                _funcCreator = "getGameModule";
                _funcDestructor = "destroyGameModule";
            }
        }

        ~LibHandler() {
            destroyLib();
        }

        static LibType getLibType(const std::string &path, void *lib = nullptr)
        {
            typedef LibType (*retType_t)();
            retType_t func = nullptr;
            LibType type;
            bool destroyAfter = true;
 
            if (lib == nullptr) {
                lib = dlopen(path.c_str(), RTLD_LAZY);
                destroyAfter = false;
            }
            if (lib == nullptr) {
                std::cout << "Error1: " << path << std::endl;
                throw std::runtime_error("Failed to load library");
            }
            func = (retType_t) dlsym(lib, "getType");
            type = func();
            if (destroyAfter) {
                dlclose(lib);
            }
            return type;
        }

        static std::string getLibName(const std::string &path, void *lib = nullptr)
        {
            typedef const char *(*retType_t)();
            retType_t func = nullptr;
            std::string name;
            bool destroyAfter = true;
 
            if (lib == nullptr) {
                lib = dlopen(path.c_str(), RTLD_LAZY);
                destroyAfter = false;
            }
            if (lib == nullptr) {
                std::cout << "Error2: " << path << std::endl;
                throw std::runtime_error("Failed to load library");
            }
            func = (retType_t) dlsym(lib, "getName");
            name = func();
            if (destroyAfter) {
                dlclose(lib);
            }
            return name;
        }

        void loadLib(const std::string &path)
        {
            typedef T *(*retType_t)();
            retType_t func = nullptr;

            std::cout << "Loading lib reeeee: " << path << std::endl;
            destroyLib();
            std::cout << "Loading lib raaaaa: " << path << std::endl;
            _lib = dlopen(path.c_str(), RTLD_LAZY);
            std::cout << "Loading lib rbbbbb: " << path << std::endl;
            if (_lib == nullptr) {
                std::cout << "Error3: " << path << std::endl;
                throw std::runtime_error("Failed to load library");
            }
            if (_type != LibHandler::getLibType(path, _lib)) {
                throw std::runtime_error("Bad library type");
            }
            std::cout << "Loading lib rccccc: " << path << std::endl;
            try {
                _name = LibHandler::getLibName(path, _lib);
            } catch (std::exception &e) {
                dlclose(_lib);
                _lib = nullptr;
                throw std::runtime_error(e.what());
            }
            std::cout << "Loading lib rddddd: " << path << std::endl;
            func = (retType_t) dlsym(_lib, _funcCreator.c_str());
            if (func == nullptr) {
                throw std::runtime_error("Failed to load function " + _funcCreator);
            }
            std::cout << "Loading lib rfffff: " << path << std::endl;
            _module = func();
            std::cout << "Loading lib rggggg: " << path << std::endl;
        }

        T *getModule()
        {
            if (_module == nullptr) {
                throw std::runtime_error("Module not loaded");
            }
            return _module;
        }

        void destroyLib()
        {
            typedef void (*retType_t)(T *);
            retType_t func = nullptr;

            if (_lib == nullptr) {
                return;
            }
            if (_module != nullptr) {
                func = (retType_t) dlsym(_lib, _funcDestructor.c_str());
                if (func != nullptr) {
                    func(_module);
                }
                _module = nullptr;
            }
            dlclose(_lib);
            _lib = nullptr;
        }

        LibType getType()
        {
            return _type;
        }
        const std::string &getName()
        {
            return _name;
        }

    private:
        std::string _funcCreator;
        std::string _funcDestructor;
        void *_lib;
        T *_module;
        LibType _type;
        std::string _name;
};
