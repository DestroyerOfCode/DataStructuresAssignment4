//
// Created by prepelicamangalica on 14/04/22.
//

#include <string>
#include "StringUtils.h"
#include <fstream>

std::string StringUtils::lastStringWord(const std::string &text) {
    int i = text.length() - 1;

    if (isspace(text[i]))
        while (isspace(text[i])) i--;

    while (i != 0 && !isspace(text[i])) --i;

    std::string lastWord = text.substr(i + 1);
    return lastWord;
}

std::string StringUtils::loadLine(std::string row, std::ifstream &inFile) {
    std::getline(inFile, row);
    return row;
}