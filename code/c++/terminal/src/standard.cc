#include "standard.h"
#include "sleep.h"
#include <iostream>
#include <limits>

/**
 * @brief Process the choice made by the user.
 * 
 * @param choices The choices available to the user.
 * @return char The choice made by the user.
 */
char processChoice(std::vector<char> &choices) {
    char choice;
    std::cin >> choice;
    for (size_t i = 0; i < choices.size(); i++) {
        if (choice == choices[i]) {
            return choice;
        }
    }
    return '\\';
}

/**
 * @brief Process the choice of the user
 * 
 * @param choices The vector of correct choices
 * @param choice The choice of the user
 */
void processChoice(std::vector<char> &choices, char &choice) {
    std::cin >> choice;
    for (size_t i = 0; i < choices.size(); i++) {
        if (choice == choices[i]) {
            return;
        }
    }
    choice = '\\';
}

/**
 * @brief Clear the screen.
 * 
 * We do this to make the program look nicer.
 */
void clearScreen() {
    // Use system("clear") on Linux and "cls" on Windows.
    #if defined(_WIN32) || defined(_WIN64)
        if (system("cls") == -1) {
            std::cout << "Failed to clear screen." << std::endl;
            std::cout << "Trying again..." << std::endl;
            if (system("cls") == -1) {
                std::cout << "Failed to clear screen." << std::endl;
                std::cout << "Charging up the super-computer...";
                for (int i = 10; i > 0; i--) {
                    std::cout << ".";
                    sleepForTime(10*i);
                }
                std::cout << std::endl;
                std::cout << "\033[2J\033[1;1H";
            }
        }
    #elif __linux__
        if (system("clear") == -1) {
            std::cout << "Failed to clear screen." << std::endl;
            std::cout << "Trying again..." << std::endl;
            if (system("clear") == -1) {
                std::cout << "Failed to clear screen." << std::endl;
                std::cout << "Charging up the super-computer...";
                for (int i = 10; i > 0; i--) {
                    std::cout << ".";
                    sleepForTime(10*i);
                }
                std::cout << std::endl;
                std::cout << "\033[2J\033[1;1H";
            }
        }
    #elif __APPLE__
        if (system("clear") == -1) {
            std::cout << "Failed to clear screen." << std::endl;
            std::cout << "Trying again..." << std::endl;
            if (system("clear") == -1) {
                std::cout << "Failed to clear screen." << std::endl;
                std::cout << "Charging up the super-computer...";
                for (int i = 10; i > 0; i--) {
                    std::cout << ".";
                    sleepForTime(10*i);
                }
                std::cout << std::endl;
                std::cout << "\033[2J\033[1;1H";
            }
        }
    #else
        std::cout << "Charging up the super-computer...";
        for (int i = 10; i > 0; i--) {
            std::cout << "."
            sleepForTime(10*i);
        }
        std::cout << std::endl;
        // for (hoogte scherm) std::cout << "\n";
        std::cout << "\033[2J\033[1;1H";
    #endif
}

/**
 * @brief Press enter to continue.
 * 
 */
void pressEnter() {
    std::cout << "Press ENTER to continue..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * @brief Print a loading animation.
 * 
 */
void loadingDots() {
    for (int i = 0; i < 5; i++) {
        std::cout << ".";
        sleepForTime(100);
    }
    std::cout << std::endl;
}

/**
 * @brief Loading dots with a custom amount of dots.
 * 
 * @param n The amount of dots to print.
 */
void loadingDots(const int &n) {
    for (int i = 0; i < n; i++) {
        std::cout << ".";
        sleepForTime(500);
    }
    std::cout << std::endl;
}

/**
 * @brief Generate a random string.
 * 
 * @param n The length of the string.
 * @return char* The random string.
 */
char* randomString(const int &n) {
    char* str = new char[n];
    for (int i = 0; i < n; i++) {
        str[i] = (char) (rand() % 26 + 97);
    }
    return str;
}

/**
 * @brief Shutdown the program.
 * 
 * @return int The exit code.
 */
int shutdown() {
    clearScreen();
    std::cout << "Shutting down... ";
    std::cout << "Goodbye!" << std::endl;
    return 0;
}

