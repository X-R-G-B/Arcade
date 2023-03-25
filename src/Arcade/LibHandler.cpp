#include <dlfcn.h>
#include <stdexcept>
#include "LibHandler.hpp"

LibHandler::LibHandler(const std::string &, LibType type) : _lib(nullptr), _module(nullptr), _type(std::nullopt) {
    loadLib(lib);
    _module = loadFunction();
}

LibHandler::~LibHandler() {
    deleteLib();
    callDestroyFunction();
}

void LibHandler::loadLib(const std::string &lib)
{
    deleteLib();
    _lib = dlopen(lib.c_str(), RTLD_LAZY);
    if (!_lib) {
        throw std::runtime_error(dlerror());
    }
}

void LibHandler::deleteLib()
{
    if (_lib) {
        if (dlclose(_lib) < 0) {
            throw std::runtime_error(dlerror());
        }
    }
}
