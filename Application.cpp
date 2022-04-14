//
// Created by prepelicamangalica on 14/04/2022.
//

#include <string>
#include <iostream>
#include <utility>
#include "Application.h"
#include "BinTree.h"

int Application::exit(BinTree* pTree) {
    delete pTree;
    return 0;
}

int Application::run() {

    std::string command;
    BinTree *binaryTree = new BinTree();

    printMenu();
    while (true) {

        try {
            getline(std::cin, command);
            switch (*command.c_str()) {
                case 'a':
                    binaryTree = new BinTree("A je to suchozemec?");
                    binaryTree->createLeft("A je to psovita selma?");
                    binaryTree = binaryTree->moveLeft();
                    binaryTree->createLeft("A je to Rysova selma?");
                    binaryTree = binaryTree->moveLeft();
                    binaryTree->createLeft("A je rys?");

                    break;
                case 'b':
                    makeLeft(binaryTree);
                    break;
                case 'c':
                    makeRight(binaryTree);
                    break;
                case 'd':
                    binaryTree = moveToRoot(binaryTree);
//                    binaryTree = binaryTree->moveToRoot();
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
                    return exit(binaryTree);
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

void Application::validation(BinTree *pTree) {

    if (nullptr == pTree) {
        throw std::runtime_error("Seems you did not initialize your tree yet!\n");
    }

}

BinTree *Application::makeLeft(BinTree *pTree) {
    std::string question = getUserInputText("What is the question you want to ask??");

    validation(pTree);

    return pTree->createLeft(question);

}

BinTree *Application::makeLeft(BinTree *pTree, std::string question) {
    validation(pTree);

    return pTree->createLeft(std::move(question));

}

BinTree *Application::makeRight(BinTree *pTree, std::string question) {

    validation(pTree);

    return pTree->createRight(std::move(question));

}

BinTree *Application::makeRight(BinTree *pTree) {
    std::string question = getUserInputText("What is the question you want to ask??");

    validation(pTree);

    return pTree->createRight(question);

}

std::string Application::getUserInputText(std::string consolePrintText) const {

    std::cout << consolePrintText << std::endl;
    std::string text;

    std::getline(std::cin, text, '\n');

    return text;
}

void Application::print(BinTree *pTree) {

    std::cout << "Question: " << pTree->getQuestion() << std::endl << "Left: ";
    pTree->getLeft() == nullptr ? std::cout << "Empty" << std::endl
                                : std::cout << pTree->getLeft()->getQuestion() << std::endl;
    std::cout << "Right: ";
    pTree->getRight() == nullptr ? std::cout << "Empty" << std::endl
                                 : std::cout << pTree->getRight()->getQuestion() << std::endl;

}

void Application::playGame(BinTree *pTree) {

    pTree = moveToRoot(pTree);
    std::string answer;

    while (true) {
        try {
            answer = getUserInputText(pTree->getQuestion());
            if ("y" == answer) {
                if (!isLastNode(pTree->getLeft())) {
                    pTree = pTree->moveLeft();
                    continue;
                }
                    std::cout << "Uhádol som!" << std::endl;
                    answer = getUserInputText("Chcete hrať znova (y/n)?");
                    if ("n" == answer) {
                        break;
                    }
            } else if ("n" == answer) {
                if (!isLastNode(pTree->getRight())) {
                    pTree = pTree->moveRight();
                    continue;
                }
                pTree = lostGame(pTree);

                answer = getUserInputText("Chcete hrať znova (y/n)?");
                    if ("n" == answer) {
                        break;
                    }

            } else {
                throw std::runtime_error("Wrong input, Write \"y\" or \"n\n");
            }
        } catch (std::runtime_error &e) {
            std::cerr << e.what() << std::endl;

        }
        pTree = moveToRoot(pTree);
    }

}

BinTree *Application::lostGame(BinTree *pTree) {
    const std::string animalName = getUserInputText("Vyhral si! Na aké zviera myslíš?");
    const std::string question = getUserInputText(
            "Zadaj otazku tak,aby bola odpoved \"ano\" pre " + animalName + " a \"nie\" pre " +
            lastStringWord(pTree->getQuestion()));

    makeRight(pTree, "Je to " + lastStringWord(question) + "?");
    pTree = pTree->moveRight();
    makeLeft(pTree, "Je to " + animalName + "?");
    return pTree;
}

std::string Application::lastStringWord(const std::string &text) {
    int i = text.length() - 1;

    if (isspace(text[i]))
        while (isspace(text[i])) i--;

    while (i != 0 && !isspace(text[i])) --i;

    std::string lastword = text.substr(i + 1);
    return lastword;
}

bool Application::isLastNode(const BinTree *pTree) const {
    return nullptr == pTree;
}

BinTree *Application::moveToRoot(BinTree *pTree) {
    while (pTree->getParent() != nullptr) {
        pTree = pTree->moveUp();
    }
    return pTree;
}
