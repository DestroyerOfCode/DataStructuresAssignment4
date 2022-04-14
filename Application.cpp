//
// Created by prepelicamangalica on 14/04/2022.
//

#include <string>
#include <iostream>
#include "Application.h"

int Application::exit() {
    return 0;
}

int Application::run() {

    char command;

    printMenu();
    while (true) {
        std::string word;
        std::string row;

        scanf("%c", &command);
        switch (command) {
            case 'a':
                break;
            case 'b':
                break;
            case 'c':
                break;
            case 'd':
                break;
            case 'e':
                break;
            case 'f':
                break;
            case 'g':
                break;
            case 'h':
                break;
            case 'i':
                break;
            case 'x':
                return exit();
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
