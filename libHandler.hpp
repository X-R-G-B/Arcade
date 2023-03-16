#include <string>

class libHandler {
    public:
        loadLib(const std::string &);
    private:
        void *_lib;
        void *loadFunction(void *handle, const char *symbol);
};
// ton extern met le dans le cpp

