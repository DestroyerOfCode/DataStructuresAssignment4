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

    void print(Tree *pTree);

    void playGame(Tree *pTree);

    std::string getUserInputText(std::string consolePrintText) const;

    bool isLastNode(const Tree *pTree) const;

    std::string lastStringWord(const std::string &text);

    Tree *makeRight(Tree *pTree, std::string question);

    Tree *makeLeft(Tree *pTree, std::string question);

    Tree *moveToRoot(Tree *pTree);

    Tree *lostGame(Tree *pTree);
};


#endif //DATASTRUCTURES_ZADANIE_4_APPLICATION_H
