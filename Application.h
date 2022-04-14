//
// Created by prepelicamangalica on 14/04/2022.
//

#ifndef DATASTRUCTURES_ZADANIE_4_APPLICATION_H
#define DATASTRUCTURES_ZADANIE_4_APPLICATION_H


#include "Tree.h"

class Application {
public:
    int run();

private:
    void printMenu();

    int exit();

    Tree *makeLeft(Tree *pTree);

    void validation(Tree *pTree);

    Tree *makeRight(Tree *pTree);

    std::string getUserInputText() const;

    void print(Tree *pTree);

    void playGame(Tree *pTree);
};


#endif //DATASTRUCTURES_ZADANIE_4_APPLICATION_H
