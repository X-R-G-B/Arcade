#include <string>
#include <functional>

class LibHandler {
    public:
        LibHandler();
        LibHandler(const std::string &);
        ~LibHandler();
        void loadLib(const std::string &);
        void deleteLib();
        template<typename resType>
        resType loadFunction(const std::string &function);
    private:
        void *_lib;
};
