/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Save Score
*/

#include <string>
#include <map>

namespace SaveScore {
    class SaveScore {
        public:
            SaveScore(const std::string &fileName, const std::string &delim = ":::");

            void saveScore(const std::map<std::string, std::string> &scores);
            std::map<std::string, std::string> loadScore();

        private:
            std::string _fileName;
            std::string _delim;
    };
}
