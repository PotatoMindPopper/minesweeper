#include "../include/menu.h"
#include "../include/constants.h"
#include "../include/standard.h"
#include "../include/table.h"
#include <iostream>

int main(int argc, char **argv) {
    bool debugMode{false};
    if (argc < 2) {
        debugMode = false;
    } else if (argc == 2) {
        if (std::string(argv[1]) == "-d") {
            debugMode = true;
        } else {
            debugMode = false;
        }
    } else {
        debugMode = false;
    }

    if (debugMode) {
        std::cout << "Debug mode is on" << std::endl;
        TableUPtr table = std::make_unique<Table>(10, 10, 10);
        char choice{'\0'};
        while (choice != 'Q') {
            choice = debugMenu();
            switch (choice) {
                case 'N': case 'n':
                    table->newGame();
                    break;
                case 'L': case 'l':
                    table->loadGame();
                    break;
                case 'S': case 's':
                    table->saveGame();
                    break;
                case 'H': case 'h':
                    table->showHighscoreTable();
                    break;
                case 'O': case 'o':
                    table->options();
                    break;                    
                case 'Q': case 'q':
                    table.reset();
                    choice = 'Q';
                    break;
                default:
                    std::cout << "Invalid choice" << std::endl;
                    break;
            }
        }
    } else {
        Choices choices;

        printIntro();
        while (choices.type != Choices::Type::End) {
            printMenu();
            getChoice(choices.str);
            processChoice(choices);

            switch (choices.type) {
                case Choices::Type::Intro:
                    printIntro();
                    break;
                case Choices::Type::Start:
                    break;
                case Choices::Type::Options:
                    break;
                case Choices::Type::End:
                    break;
                case Choices::Type::Wrong:
                    wrongChoice();
                    break;
                default:
                    break;
            }
        }
    }

    return shutdown();
}

