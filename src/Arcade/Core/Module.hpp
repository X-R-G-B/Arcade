/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** module class
*/

#include <memory>
#include <vector>
#include "LibHandler.hpp"

namespace Arcade
{
    namespace Core
    {
        class Module
        {
        public:
            Module(std::vector<std::string> libsNames);

        protected:
            std::unique_ptr<LibHandler> getLibHandler(const std::string &libName);
            void changelib();
            void nextLib();
            std::vector<std::string> _libsNames;
            std::string _currentLib;
        };
    }
}
