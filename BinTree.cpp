//
// Created by prepelicamangalica on 14/04/2022.
//

#include <iostream>
#include "BinTree.h"

BinTree::BinTree() {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    question = "";
}

BinTree::BinTree(const std::string &question) : question(question) {
    parent = nullptr;
    left = nullptr;
    right = nullptr;

}

BinTree::BinTree(BinTree *tree) {
    parent = tree->parent;
    left = tree->left;
    right = tree->right;
    question = tree->question;
}

const std::string &BinTree::getQuestion() const {
    return question;
}

void BinTree::setQuestion(const std::string &question) {
    BinTree::question = question;
}

BinTree *BinTree::getLeft() const {
    return left;
}

void BinTree::setLeft(BinTree *left) {
    BinTree::left = left;
}

BinTree *BinTree::getRight() const {
    return right;
}

void BinTree::setRight(BinTree *right) {
    BinTree::right = right;
}

BinTree::~BinTree() {
    std::cout << "bye\n";
}

BinTree *BinTree::moveRight() {
    if (nullptr == getRight()) {
        return this;
    }

    return getRight();
}

BinTree *BinTree::moveLeft() {
    if (nullptr == getLeft()) {
        return this;
    }

    return getLeft();
}

BinTree *BinTree::moveUp() {
    if (nullptr == getParent()) {
        return this;
    }

    return getParent();
}

BinTree *BinTree::moveToRoot() {
    BinTree *temp = this;
    while (getParent() != nullptr) {
        temp = moveUp();
        setParent(temp->getParent());
    }

    return temp;
}

BinTree *BinTree::getParent() const {
    return parent;
}

void BinTree::setParent(BinTree *parent) {
    BinTree::parent = parent;
}

BinTree *BinTree::createLeft(std::string text) {
    BinTree *newNode = new BinTree(text);
    newNode->setQuestion(text);

    newNode->setParent(this);
    setLeft(newNode);

    return newNode->getLeft();
}

BinTree *BinTree::createRight(std::string text) {
    BinTree *newNode = new BinTree(text);
    newNode->setQuestion(text);

    newNode->setParent(this);
    setRight(newNode);

    return newNode->getRight();
}
