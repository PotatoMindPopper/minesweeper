#include "standard.h"
#include <iostream>

void clearScreen() {
    int success = -1;

    #if defined(_WIN32) || defined(_WIN64)
        success = system("cls");
    #else
        success = system("clear");
    #endif

    if (success != 0) {
        std::cerr << "Error: Failed to clear the screen." << std::endl;
        std::cout << "Press enter to try again." << std::endl;
        std::cin.get();
        std::cout << "\033[2J\033[1;1H";
    }
}
