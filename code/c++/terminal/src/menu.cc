#include "../include/menu.h"

Menu::Menu() {
    // Do nothing
}

Menu::~Menu() {
    currentTable.reset();
    currentTable = nullptr;
    tables.empty();
}

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

void Menu::getChoice() {
    std::cout << "Enter your choice: ";
    std::cin.ignore();
    std::getline(std::cin, choices.str);
}

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
    std::cout << "Your answer: " << this->choices.str << std::endl;
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

void Menu::resetChoices() {
    this->choices.type = Choices::Type::Undefined;
}