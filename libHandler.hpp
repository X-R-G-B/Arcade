#include <string>
#include <functional>

class libHandler {
    public:
        libHandler();
        libHandler(const std::string &);
        ~libHandler();
        void loadLib(const std::string &);
        void deleteLib();
        template<typename FuncType>
        std::function<FuncType> loadFunction();
    private:
        void *_lib;
        void *loadFunction(void *handle, const char *symbol);
};
