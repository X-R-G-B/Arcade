/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** LibHandler class
*/

#pragma once

#include <cstdio>
#include <iostream>
#include <string>
#include <dlfcn.h>
#include <functional>
#include <stdexcept>
#include <type_traits>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "Api.hpp"
#include "Exceptions.hpp"

/**
 * @brief The LibHandler class
 *
 * @tparam T type that this class will handle (could be IDisplayModule IGameModule)
 */
template<typename T = int>
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
            } else {
                throw ArcadeExceptions("LibHandler: wrong type (type handler are IDisplayModule IGameModule)");
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
            bool destroyAfter = false;
 
            if (lib == nullptr) {
                lib = dlopen(path.c_str(), RTLD_LAZY);
                destroyAfter = true;
            }
            if (lib == nullptr) {
                throw ArcadeExceptions("Failed to load library in getLibType");
            }
            func = (retType_t) dlsym(lib, "getType");
            if (func == nullptr) {
                throw ArcadeExceptions("Failed to load function getType");
            }
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
            bool destroyAfter = false;
 
            if (lib == nullptr) {
                lib = dlopen(path.c_str(), RTLD_LAZY);
                destroyAfter = true;
            }
            if (lib == nullptr) {
                throw ArcadeExceptions("Failed to load library in getLibName");
            }
            func = (retType_t) dlsym(lib, "getName");
            if (func == nullptr) {
                throw ArcadeExceptions("Failed to load function getName");
            }
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
            LibType type;

            destroyLib();
            _lib = dlopen(path.c_str(), RTLD_LAZY);
            if (_lib == nullptr) {
                throw ArcadeExceptions("Failed to load library in loadLib");
            }
            try {
                type = this->getLibType(path, _lib);
            } catch (const std::exception &e) {
                destroyLib();
                throw ArcadeExceptions(e.what());
            }
            if (_type != type) {
                destroyLib();
                throw ArcadeExceptions("Bad library type");
            }
            try {
                _name = LibHandler::getLibName(path, _lib);
            } catch (const std::exception &e) {
                destroyLib();
                throw ArcadeExceptions(e.what());
            }
            func = (retType_t) dlsym(_lib, _funcCreator.c_str());
            if (func == nullptr) {
                throw ArcadeExceptions("Failed to load function " + _funcCreator);
            }
            _module = func();
        }

        T *getModule()
        {
            return _module;
        }

        void reset()
        {
            destroyLib();
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

        std::string _funcCreator;
        std::string _funcDestructor;
        void *_lib;
        T *_module;
        LibType _type;
        std::string _name;
};
