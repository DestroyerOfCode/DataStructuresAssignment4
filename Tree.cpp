//
// Created by prepelicamangalica on 14/04/2022.
//

#include "Tree.h"

Tree::Tree() {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    question = "";
}

Tree::Tree(const std::string &question) : question(question) {
    parent = nullptr;
    left = nullptr;
    right = nullptr;

}

Tree::Tree(Tree *tree) {
    parent = tree->parent;
    left = tree->left;
    right = tree->right;
    question = tree->question;
}

const std::string &Tree::getQuestion() const {
    return question;
}

void Tree::setQuestion(const std::string &question) {
    Tree::question = question;
}

Tree *Tree::getLeft() const {
    return left;
}

void Tree::setLeft(Tree *left) {
    Tree::left = left;
}

Tree *Tree::getRight() const {
    return right;
}

void Tree::setRight(Tree *right) {
    Tree::right = right;
}

Tree *Tree::moveRight() {
    return nullptr;
}

Tree *Tree::moveLeft() {
    return nullptr;
}

Tree *Tree::moveUp() {
    return nullptr;
}

Tree *Tree::moveRoot() {
    return nullptr;
}

Tree::~Tree() {

}

Tree *Tree::getParent() const {
    return parent;
}

void Tree::setParent(Tree *parent) {
    Tree::parent = parent;
}

Tree *Tree::createLeft(std::string text) {
    Tree *newNode = new Tree(text);
    newNode->setQuestion(text);

    newNode->setParent(this);
    setLeft(newNode);

    return newNode->getLeft();
}

Tree *Tree::createRight(std::string text) {
    Tree *newNode = new Tree(text);
    newNode->setQuestion(text);

    newNode->setParent(this);
    setRight(newNode);

    return newNode->getRight();
}
