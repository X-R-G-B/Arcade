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

extern "C" void libHandler::loadLib(const std::string &lib)
{
    deleteLib();
    _lib = dlopen(lib.c_str(), RTLD_LAZY);
    if (!_lib) {
        throw std::runtime_error(dlerror());
    }
}

extern "C" int libHandler::deleteLib()
{
    if (_lib) {
        return dlclose(_lib);
    }
    return -1;
}

template<typename FuncType>
extern "C" std::function<FuncType> libHandler::loadFunction()
{
    //dlsym
}