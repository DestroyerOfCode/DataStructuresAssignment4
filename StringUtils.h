//
// Created by prepelicamangalica on 14/04/22.
//

#ifndef DATASTRUCTURES_ZADANIE_4_STRINGUTILS_H
#define DATASTRUCTURES_ZADANIE_4_STRINGUTILS_H


class StringUtils {
public:
    static std::string lastStringWord(const std::string &text);

    static std::string loadLine(std::string row, std::ifstream &inFile);
};


#endif //DATASTRUCTURES_ZADANIE_4_STRINGUTILS_H
