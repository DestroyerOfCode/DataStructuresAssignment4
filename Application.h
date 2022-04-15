//
// Created by prepelicamangalica on 14/04/2022.
//

#ifndef DATASTRUCTURES_ZADANIE_4_APPLICATION_H
#define DATASTRUCTURES_ZADANIE_4_APPLICATION_H


#include "BinTree.h"

class Application {
public:
    int run();

private:
    void printMenu();

    BinTree *makeLeft(BinTree *pTree);

    void validation(BinTree *pTree);

    BinTree *makeRight(BinTree *pTree);

    void print(BinTree *pTree);

    void playGame(BinTree *pTree);

    std::string getUserInputText(const std::string& consolePrintText) const;

    bool isLastNode(const BinTree *pTree) const;

    BinTree *makeRight(BinTree *pTree, std::string question);

    BinTree *makeLeft(BinTree *pTree, std::string question);

    BinTree *lostGame(BinTree *pTree);

    int exit(BinTree *pTree);

    void createNodeInLeftCorner(BinTree *pTree, const std::string &animalName, const std::string &question);

    BinTree *createNodeInRightCorner(BinTree *pTree, const std::string &animalName, const std::string &question);
};


#endif //DATASTRUCTURES_ZADANIE_4_APPLICATION_H
