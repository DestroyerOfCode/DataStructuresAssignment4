//
// Created by prepelicamangalica on 14/04/2022.
//

#include "Tree.h"

Tree::Tree() {}

Tree *Tree::getRoot() const {
    return root;
}

void Tree::setRoot(Tree *root) {
    Tree::root = root;
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

const std::string &Tree::getQuestion() const {
    return question;
}

Tree *Tree::createRight(Tree *) {
    return nullptr;
}

Tree *Tree::createLeft(Tree *) {
    return nullptr;
}

Tree *Tree::moveRight(Tree *) {
    return nullptr;
}

Tree *Tree::moveLeft(Tree *) {
    return nullptr;
}

Tree *Tree::moveUp(Tree *) {
    return nullptr;
}

Tree *Tree::moveRoot(Tree *) {
    return nullptr;
}
