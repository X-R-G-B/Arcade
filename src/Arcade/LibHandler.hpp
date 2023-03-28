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
                throw std::exception();
            }
            func = (retType_t) dlsym(lib, "getType");
            if (func == nullptr) {
                throw std::exception();
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
                throw std::exception();
            }
            std::cout << "lib = " << lib << std::endl;
            std::cout << "path = " << path << std::endl;
            func = (retType_t) dlsym(lib, "getName");
            if (func == nullptr) {
                std::puts("ntmeee");
                throw std::exception();
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
                throw std::exception();
            }
            try {
                type = this->getLibType(path, _lib);
            } catch (const std::exception &e) {
                destroyLib();
                throw std::exception();
            }
            if (_type != type) {
                destroyLib();
                throw std::exception();
            }
            try {
                _name = LibHandler::getLibName(path, _lib);
            } catch (const std::exception &e) {
                destroyLib();
                throw std::runtime_error(e.what());
            }
            func = (retType_t) dlsym(_lib, _funcCreator.c_str());
            if (func == nullptr) {
                throw std::runtime_error("Failed to load function " + _funcCreator);
            }
            _module = func();
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
