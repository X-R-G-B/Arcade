#include <string>
#include <functional>

class libHandler {
    public:
        libHandler();
        libHandler(const std::string &);
        ~libHandler();
        void loadLib(const std::string &);
        void deleteLib();
        template<typename resType>
        resType loadFunction(const std::string &function);
    private:
        void *_lib;
};
