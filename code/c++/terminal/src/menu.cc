#include "../include/menu.h"

#include <iostream>
#include <stack>
#include <string>

Menu::Menu() {
    // Do nothing
}

Menu::~Menu() {
    currentTable = nullptr;
    tables = std::stack<TableSPtr>();
}

/**
 * @brief Prints the introduction to the program.
 * 
 */
void Menu::printIntro() {
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
    this->processMainMenu();
}

/**
 * @brief Prints the main menu of the program.
 * 
 */
void Menu::printMainMenu() {
    clearScreen();
    std::cout << "======================================================" << std::endl;
    std::cout << "|                        MENU                        |" << std::endl;
    std::cout << "|---------+------------------------------------------|" << std::endl;
    std::cout << "|   [I]   |   Introduction                           |" << std::endl;
    std::cout << "|   [S]   |   Start game                             |" << std::endl;
    std::cout << "|   [O]   |   Options                                |" << std::endl;
    std::cout << "|   [Q]   |   Quit game                              |" << std::endl;
    std::cout << "|---------+------------------------------------------|" << std::endl;
    std::cout << "|      More information: https://minesweeper.ml      |" << std::endl;
    std::cout << "======================================================" << std::endl;
}

/**
 * @brief Prints an error screen, for faulty input.
 * 
 */
void Menu::wrongChoice() {
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
    std::cout << "Your answer: '" << this->choices.str << "'" << std::endl;
    pressEnter();
}

char Menu::debugMenu() {
    std::cout << "Menu: " << std::endl;
    std::cout << "  [P] Play" << std::endl;
    std::cout << "  [N] New game" << std::endl;
    std::cout << "  [L] Load game" << std::endl;
    std::cout << "  [S] Save game" << std::endl;
    std::cout << "  [H] Highscore" << std::endl;
    std::cout << "  [O] Options" << std::endl;
    std::cout << "  [Q] Quit game" << std::endl;
    std::cout << "Enter your choice: ";

    char choice{'\0'};
    bool correct{false};
    while (!correct) {
        std::cin >> choice;
        char check = std::toupper(choice);
        switch (check) {
            case 'N': case 'L': case 'S': case 'H': case 'O': case 'Q': case 'P':
                correct = true;
                break;
            default:
                std::cout << "Wrong choice! Try again: ";
                break;
        }
    }
    return choice;
}

/**
 * @brief Get choice from user into the program.
 * 
 */
void Menu::getChoice() {
    std::cout << "Enter your choice: ";

    // Makes it so that everything is ignored until a new line is entered, 
    //  which is not what we want.
    // std::cin.ignore();

    // std::cin.getline(this->choices.str, 2);

    std::getline(std::cin, choices.str);
}

/**
 * @brief Processes the user input into a choice type
 * 
 */
void Menu::processMainChoice() {
    this->getChoice();

    if (this->choices.str.length() == 1) {
        this->choices.choice = choices.str[0];
        this->choices.choice = std::toupper(this->choices.choice);
        switch (this->choices.choice) {
            case 'I': case 'i':
                this->choices.type = Choices::Type::Intro;
                break;
            case 'S': case 's':
                this->choices.type = Choices::Type::Start;
                break;
            case 'O': case 'o':
                this->choices.type = Choices::Type::Options;
                break;
            case 'Q': case 'q':
                this->choices.type = Choices::Type::End;
                break;
            default:
                this->choices.type = Choices::Type::Wrong;
                break;
        }
    } else {
        this->choices.type = Choices::Type::Wrong;
    }
}

/**
 * @brief Processes the input and starts calling functions.
 * 
 */
void Menu::processMainMenu() {
    while (this->choices.type != Choices::Type::End) {
        this->printMainMenu();
        processMainChoice();
        switch (this->choices.type) {
            case Choices::Type::Intro:
                this->resetChoices();
                this->printIntro();
                break;
            case Choices::Type::Start:
                this->resetChoices();
                currentTable->newGame();
                this->gameMenu();
                break;
            case Choices::Type::Options:
                this->resetChoices();
                this->optionsMenu();
                break;
            case Choices::Type::Wrong:
                this->resetChoices();
                this->wrongChoice();
                break;
            default:
                break;
        }
    }
}

/**
 * @brief Resets the type.
 * 
 * This is needed because choices will be used multiple times.
 */
void Menu::resetChoices() {
    this->choices.type = Choices::Type::Undefined;
}

/**
 * @brief Run the game.
 * 
 * This will startup the table screen with all the game options.
 */
void Menu::gameMenu() {
    // Run the actual game.
}

/**
 * @brief Prints a settings menu.
 * 
 * This can reset the table values, based upon the input.
 */
void Menu::optionsMenu() {
    // Maybe reset some table values or clear board.
}
