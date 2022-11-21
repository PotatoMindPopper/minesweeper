#ifndef __MENU_H__
#define __MENU_H__

#include "standard.h"
#include <iostream>

struct Choices {
    enum Type {
        Undefined,
        Intro,
        Start,
        End,
        Wrong
    } type{Undefined};
    std::string str{""};
    char choice{'\0'};
};

void printIntro() {
    clearScreen();
    std::cout << "======================================================" << std::endl;
    std::cout << "|                    INTRODUCTION                    |" << std::endl;
    std::cout << "|----------------------------------------------------|" << std::endl;
    std::cout << "|                                                    |" << std::endl;
    std::cout << "|                                                    |" << std::endl;
    std::cout << "|               Welcome to Minesweeper               |" << std::endl;
    std::cout << "|                                                    |" << std::endl;
    std::cout << "|                                                    |" << std::endl;
    std::cout << "|----------------------------------------------------|" << std::endl;
    std::cout << "|                                                    |" << std::endl;
    std::cout << "|                      --TEXT--                      |" << std::endl;
    std::cout << "|                      --TEXT--                      |" << std::endl;
    std::cout << "|                      --TEXT--                      |" << std::endl;
    std::cout << "|                      --TEXT--                      |" << std::endl;
    std::cout << "|                      --TEXT--                      |" << std::endl;
    std::cout << "|                      --TEXT--                      |" << std::endl;
    std::cout << "|                      --TEXT--                      |" << std::endl;
    std::cout << "|                      --TEXT--                      |" << std::endl;
    std::cout << "|                                                    |" << std::endl;
    std::cout << "|----------------------------------------------------|" << std::endl;
    std::cout << "|               This is written in C++               |" << std::endl;
    std::cout << "|----------------------------------------------------|" << std::endl;
    std::cout << "|      More information: https://minesweeper.ml      |" << std::endl;
    std::cout << "======================================================" << std::endl;
    pressEnter();
}

void printMenu() {
    clearScreen();
    std::cout << "======================================================" << std::endl;
    std::cout << "|                        MENU                        |" << std::endl;
    std::cout << "|---------+------------------------------------------|" << std::endl;
    std::cout << "|   [I]   |   Introduction                           |" << std::endl;
    std::cout << "|   [S]   |   Start game                             |" << std::endl;
    std::cout << "|---------+---------+--------------------------------|" << std::endl;
    std::cout << "|         |   [0]   |   Start new game               |" << std::endl;
    std::cout << "|         |   [1]   |   Load old game                |" << std::endl;
    std::cout << "|         |   [2]   |   Settings                     |" << std::endl;
    std::cout << "|         |   [3]   |   Return                       |" << std::endl;
    std::cout << "|---------+---------+--------------------------------|" << std::endl;
    std::cout << "|   [Q]   |   Quit game                              |" << std::endl;
    std::cout << "|---------+------------------------------------------|" << std::endl;
    std::cout << "|      More information: https://minesweeper.ml      |" << std::endl;
    std::cout << "======================================================" << std::endl;
}

void getChoice(std::string &choice) {
    std::cout << "Enter your choice: ";
    // Read till the end of the line
    std::getline(std::cin, choice);
}

void processChoice(Choices &choices) {
    if (choices.str.length() == 1) {
        choices.choice = choices.str[0];
        choices.choice = std::toupper(choices.choice);
        switch (choices.choice) {
            case 'I': case 'i':
                choices.type = Choices::Type::Intro;
                break;
            case 'S': case 's':
                choices.type = Choices::Type::Start;
                break;
            case 'Q': case 'q':
                choices.type = Choices::Type::End;
                break;
            default:
                choices.type = Choices::Type::Wrong;
                break;
        }
    } else {
        choices.type = Choices::Type::Wrong;
    }
}

void wrongChoice() {
    clearScreen();
    std::cout << "======================================================" << std::endl;
    std::cout << "|                        ERROR                       |" << std::endl;
    std::cout << "|----------------------------------------------------|" << std::endl;
    std::cout << "|                                                    |" << std::endl;
    std::cout << "|                   Wrongly chosen                   |" << std::endl;
    std::cout << "|             This answer does not exist             |" << std::endl;
    std::cout << "|                                                    |" << std::endl;
    std::cout << "|----------------------------------------------------|" << std::endl;
    std::cout << "|      More information: https://minesweeper.ml      |" << std::endl;
    std::cout << "======================================================" << std::endl;
    pressEnter();
}

#endif // __MENU_H__