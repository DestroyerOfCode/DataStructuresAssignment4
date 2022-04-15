//
// Created by prepelicamangalica on 14/04/2022.
//

#ifndef DATASTRUCTURES_ZADANIE_4_BINTREE_H
#define DATASTRUCTURES_ZADANIE_4_BINTREE_H


#include <string>
#include <fstream>
#include <vector>

class BinTree {

public:
    BinTree *getParent() const;

    void setParent(BinTree *parent);

private:

    BinTree *left;
    BinTree *parent;
    BinTree *right;
    std::string question;

    void preOrderTraverse(BinTree *tree, std::ofstream &ofstream, int index);

public:
    virtual ~BinTree();

    explicit BinTree(BinTree *tree);

public:
    void setQuestion(const std::string &question);

    BinTree *moveUp();

    BinTree *moveLeft();

    BinTree *moveRight();

    BinTree *createLeft(std::string text);

    BinTree *createRight(std::string text);

public:

    BinTree *getLeft() const;

    void setLeft(BinTree *left);

    BinTree *getRight() const;

    void setRight(BinTree *right);

    const std::string &getQuestion() const;

public:
    BinTree();

    BinTree(const std::string &question);

    void findNodeDirections(const std::string &index, std::vector<std::string> &nodeDirections) const;

    void loadFromFile(BinTree *pTree) const;

    void setRootNode(BinTree *pTree, const std::vector<std::string> &nodeDirections, const std::string &question) const;

    BinTree *moveToRoot(BinTree *pTree);

    BinTree *
    moveToPlaceAndCreateNode(BinTree *pTree, const std::vector<std::string> &nodeDirections,
                             std::string &currentQuestion) const;
};


#endif //DATASTRUCTURES_ZADANIE_4_BINTREE_H
