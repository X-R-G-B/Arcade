/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Save Score
*/

#include <fstream>
#include <stdexcept>
#include <string>
#include "SaveScore.hpp"

SaveScore::SaveScore::SaveScore(const std::string &fileName, const std::string &delim):
    _fileName(fileName), _delim(delim)
{
    std::ofstream file(fileName, std::ios::out | std::ios::app);
}

void SaveScore::SaveScore::saveScore(const std::map<std::string, std::string> &scores)
{
    std::ofstream file(_fileName);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    for (const auto &score : scores) {
        file << score.first << _delim << score.second << std::endl;
    }
}

std::map<std::string, std::string> SaveScore::SaveScore::loadScore()
{
    std::ifstream file(_fileName);
    std::string line;
    std::map<std::string, std::string> scores;

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    while (std::getline(file, line)) {
        std::string scoreName = line.substr(0, line.find(_delim));
        std::string score = line.substr(line.find(_delim) + _delim.length());
        scores[scoreName] = score;
    }
    return scores;
}
