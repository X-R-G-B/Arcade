#include <dlfcn.h>
#include <iostream>

int main(int ac, char *av[])
{
    void *handle;

    if (ac < 2) {
        return 1;
    }
    handle = dlopen(av[1], RTLD_LAZY);
    if (!handle) {
        std::cerr << dlerror() << std::endl;
        return 2;
    }
    dlclose(handle);
}
