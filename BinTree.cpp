//
// Created by prepelicamangalica on 14/04/2022.
//

#include <iostream>
#include "BinTree.h"
#include "StringUtils.h"
#include <vector>

#define ANIMALS_FILE_PATH "./animals.txt"

BinTree::BinTree() {
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->question = "";

    loadFromFile(this);
}

void BinTree::loadFromFile(BinTree *pTree) const {
    std::ifstream inFile(ANIMALS_FILE_PATH, std::ifstream::in);
    std::string row;
    if (!inFile) {
        throw std::runtime_error("Could not open file");
    }
    while (!(row = StringUtils::loadLine(row, inFile)).empty()) {
        std::string index = StringUtils::lastStringWord(row);
        std::vector<std::string> nodeDirections;

        findNodeDirections(index, nodeDirections);
        std::string currentQuestion = row.substr(0, 1 + row.rfind('?'));

        setRootNode(pTree, nodeDirections, currentQuestion);

        pTree = moveToPlaceAndCreateNode(pTree, nodeDirections, currentQuestion);
        pTree = pTree->moveToRoot(pTree);
    }
}

BinTree *BinTree::moveToPlaceAndCreateNode(BinTree *pTree, const std::vector<std::string> &nodeDirections,
                                           std::string &currentQuestion) const {
    for (int i = 0; i < nodeDirections.size(); ++i) {
        if (i == nodeDirections.size() - 1) {
            "r" == nodeDirections[i] ? pTree->createRight(currentQuestion)
                                     : pTree->createLeft(currentQuestion);
            break;
        }
        pTree = "r" == nodeDirections[i] ? pTree->moveRight()
                                         : pTree->moveLeft();

    }
    return pTree;
}

BinTree *BinTree::moveToRoot(BinTree *pTree) {
    while (pTree->getParent() != nullptr) {
        pTree = pTree->moveUp();
    }
    return pTree;
}

void BinTree::setRootNode(BinTree *pTree, const std::vector<std::string> &nodeDirections,
                          const std::string &question) const {
    if (0 == nodeDirections.size()) {
        pTree->setQuestion(question);
    }
}

void BinTree::findNodeDirections(const std::string &index, std::vector<std::string> &nodeDirections) const {
    for (int i = std::stoi(index); i > 1; i /= 2) {
        if (i % 2 == 0) {
            nodeDirections.insert(nodeDirections.begin(), "l");
            continue;
        }
        nodeDirections.insert(nodeDirections.begin(), "r");
    }
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
    std::ofstream outFile(ANIMALS_FILE_PATH, std::ios::out);

    if (!outFile) {
        throw std::runtime_error("Could not open file");
    }

    preOrderTraverse(this, outFile, 1);
    std::cout << "bye\n";
}

void BinTree::preOrderTraverse(BinTree *tree, std::ofstream &ofstream, int index) {
    if (nullptr == tree) {
        return;
    }

    ofstream << tree->getQuestion() << " " << index << std::endl;

    preOrderTraverse(tree->getLeft(), ofstream, index * 2);
    preOrderTraverse(tree->getRight(), ofstream, index * 2 + 1);
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
