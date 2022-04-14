//
// Created by prepelicamangalica on 14/04/2022.
//

#ifndef DATASTRUCTURES_ZADANIE_4_TREE_H
#define DATASTRUCTURES_ZADANIE_4_TREE_H


#include <string>

class Tree {

private:
    Tree *root;
    Tree *left;
    Tree *right;
    const std::string question;

    Tree *moveRoot(Tree *);

    Tree *moveUp(Tree *);

    Tree *moveLeft(Tree *);

    Tree *moveRight(Tree *);

    Tree *createLeft(Tree *);

    Tree *createRight(Tree *);

public:
    Tree *getRoot() const;

    void setRoot(Tree *root);

    Tree *getLeft() const;

    void setLeft(Tree *left);

    Tree *getRight() const;

    void setRight(Tree *right);

    const std::string &getQuestion() const;

public:
    Tree();
};


#endif //DATASTRUCTURES_ZADANIE_4_TREE_H
