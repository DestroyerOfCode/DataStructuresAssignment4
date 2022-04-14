//
// Created by prepelicamangalica on 14/04/2022.
//

#ifndef DATASTRUCTURES_ZADANIE_4_BINTREE_H
#define DATASTRUCTURES_ZADANIE_4_BINTREE_H


#include <string>

class BinTree {

public:
    BinTree *getParent() const;

    void setParent(BinTree *parent);

private:

    BinTree *left;
    BinTree *parent;
    BinTree *right;
    std::string question;
public:
    virtual ~BinTree();

    explicit BinTree(BinTree *tree);

public:
    void setQuestion(const std::string &question);

    BinTree *moveToRoot();

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

    virtual ~BinTree();
};


#endif //DATASTRUCTURES_ZADANIE_4_BINTREE_H
