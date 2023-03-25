//replace main by this to test
//game module code

#include "GameModule.hpp"    

int main(int ac, char **)
{
    std::vector<std::string> v;
    v.push_back("fst");
    v.push_back("scd");
    v.push_back("trd");
    std::unique_ptr<Arcade::Core::IGameModule> gameModule = std::make_unique<Arcade::Core::GameModule>(v);
    gameModule->changeGame();
    gameModule->changeGame("trd");
    std::vector<std::string> vres = gameModule->getGamesNames();
    std::cout << vres.front() << std::endl;
    gameModule->changeGame();
    gameModule->changeGame();
}
