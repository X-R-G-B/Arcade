#include "../../../src/Api.hpp"
#include "IDisplayModule.hpp"
#include "coutModule.hpp"

LibType getType()
{
    return LibType::GRAPH;
}

const char *getName()
{
    return "graphlib name";
}

Arcade::Graph::IDisplayModule *getDisplayModule()
{
    return new Arcade::Graph::CoutModule();
}

void destroyDisplayModule(Arcade::Graph::IDisplayModule *mod)
{
    delete mod;
}
