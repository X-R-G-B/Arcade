#include <dlfcn.h>
#include <stdexcept>
#include "LibHandler.hpp"

LibHandler::LibHandler() : _lib(0) {}

LibHandler::LibHandler(const std::string &lib) : _lib(0) {
    loadLib(lib);
}

LibHandler::~LibHandler() {
    deleteLib();
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

template<typename resType>
resType LibHandler::loadFunction(const std::string &function)
{
    resType (*func)() = NULL;

    if (_lib == nullptr) {
        throw std::runtime_error("No library loaded");
    }
    func = dlsym(_lib, function.c_str());
    if (!func) {
        throw std::invalid_argument("A library in lib/ don't respect entry points doc");
    }
    return func();
}
