#include <dlfcn.h>
#include <stdexcept>
#include "libHandler.hpp"

libHandler::libHandler() : _lib(0) {}

libHandler::libHandler(const std::string &lib) : _lib(0) {
    loadLib(lib);
}

libHandler::~libHandler() {
    deleteLib();
}

void libHandler::loadLib(const std::string &lib)
{
    deleteLib();
    _lib = dlopen(lib.c_str(), RTLD_LAZY);
    if (!_lib) {
        throw std::runtime_error(dlerror());
    }
}

void libHandler::deleteLib()
{
    if (_lib) {
        if (dlclose(_lib) < 0) {
            throw std::runtime_error(dlerror());
        }
    }
}

template<typename resType>
resType libHandler::loadFunction(const std::string &function)
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
