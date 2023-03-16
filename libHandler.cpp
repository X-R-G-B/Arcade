#include "libHandler.hpp"

extern "C" loadLib(const std::string &lib)
{
    //dlopen
}

extern "C" deleteLIb(void *lib)
{
    //dlclose
}

extern "C" loadFunction(void *lib)
{
    //dlsym
}