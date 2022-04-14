//
// Created by prepelicamangalica on 14/04/2022.
//

#ifndef DATASTRUCTURES_ZADANIE_4_TREE_H
#define DATASTRUCTURES_ZADANIE_4_TREE_H


#include <string>

class Tree {

public:
    Tree *getParent() const;

    void setParent(Tree *parent);

private:

    Tree *left;
    Tree *parent;
    Tree *right;
    std::string question;
public:
    virtual ~Tree();

    explicit Tree(Tree *tree);

public:
    void setQuestion(const std::string &question);

    Tree *moveRoot();

    Tree *moveUp();

    Tree *moveLeft();

    Tree *moveRight();

    Tree *createLeft(std::string text);

    Tree *createRight(std::string text);

public:

    Tree *getLeft() const;

    void setLeft(Tree *left);

    Tree *getRight() const;

    void setRight(Tree *right);

    const std::string &getQuestion() const;

public:
    Tree();

    Tree(const std::string &question);
};


#endif //DATASTRUCTURES_ZADANIE_4_TREE_H
