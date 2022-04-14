//
// Created by prepelicamangalica on 14/04/2022.
//

#include <string>
#include <iostream>
#include "Application.h"
#include "Tree.h"

int Application::exit() {
    return 0;
}

int Application::run() {

    char command;
    Tree *binaryTree = new Tree();

    printMenu();
    while (true) {

        try {
            scanf("%c", &command);
            switch (command) {
                case 'a':
                    binaryTree = new Tree("A je to vobec zviera?");
                    break;
                case 'b':
                    makeLeft(binaryTree);
                    break;
                case 'c':
                    makeRight(binaryTree);
                    break;
                case 'd':
                    binaryTree = binaryTree->moveToRoot();
                    break;
                case 'e':
                    binaryTree = binaryTree->moveLeft();
                    break;
                case 'f':
                    binaryTree = binaryTree->moveRight();
                    break;
                case 'g':
                    binaryTree = binaryTree->moveUp();
                    break;
                case 'h':
                    print(binaryTree);
                    break;
                case 'i':
                    playGame(binaryTree);
                    break;
                case 'x':
                    return exit();
            }
        } catch (std::exception &e) {
            std::cerr << "Something went wrong:" << std::endl << e.what() << std::endl;
        }
    }

    throw std::runtime_error("Something unexpected happened");
}

void Application::printMenu() {
    std::cout << "a. Vytvorenie prázdneho stromu" << std::endl <<
              "b. Vytvorenie ľavého nasledovníka" << std::endl <<
              "c. Vytvorenie pravého nasledovníka" << std::endl <<
              "d. Nastavenie na root" << std::endl <<
              "e. Nastavenie na ľavé dieťa" << std::endl <<
              "f. Nastavenie na pravé dieťa" << std::endl <<
              "g. Nastavenie aktívneho prvku na rodiča" << std::endl <<
              "h. Vypíše hodnotu aktívneho vrcholu a jeho hodnoty ľavý a pravý (pripadne null ak nemajú dáta)"
              << std::endl <<
              "i. Spustenie hry" << std::endl <<
              "x. Ukonči program." << std::endl;
    std::cout.flush();
}

void Application::validation(Tree *pTree) {

    if (nullptr == pTree) {
        throw std::runtime_error("Seems you did not initialize your tree yet!\n");
    }

}

Tree *Application::makeLeft(Tree *pTree) {
    std::string question = getUserInputText();

    validation(pTree);

    pTree = pTree->createLeft(question);

    return pTree;
}

Tree *Application::makeRight(Tree *pTree) {
    std::string question = getUserInputText();

    validation(pTree);

    pTree = pTree->createRight(question);

    return pTree;
}

std::string Application::getUserInputText() const {

    std::string text;
    std::cout << "What is the question you want to ask??" << std::endl;
    std::cout.flush();

    std::cin >> text;

    return text;
}

void Application::print(Tree *pTree) {

    std::cout << "Parent: " << pTree->getQuestion() << std::endl << "Left: ";
    pTree->getLeft() == nullptr ? std::cout << "Empty" << std::endl
                                : std::cout << pTree->getLeft()->getQuestion() << std::endl;
    std::cout << "Right: ";
    pTree->getRight() == nullptr ? std::cout << "Empty" << std::endl
                                 : std::cout << pTree->getRight()->getQuestion() << std::endl;

}

void Application::playGame(Tree *pTree) {



}
