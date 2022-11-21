#include "menu.h"
#include "constants.h"
#include "standard.h"
#include "table.h"
#include <iostream>

int main(/*int argc, char **argv*/) {
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
            case Choices::Type::End:
                break;
            case Choices::Type::Wrong:
                wrongChoice();
                break;
            default:
                break;
        }
    }

/*
    if (argc < 2) {
        menu.runHuman();
    } else if (std::string(argv[1]) == "computer") {
        menu.runComputer();
    } else {
        menu.runHuman();
    }
*/
    std::cout << "End of program" << std::endl;

    return shutdown();
}

