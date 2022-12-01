#include "standard.h"
#include <iostream>
#include <random>

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
        // std::cin.get();
        std::cin.ignore();
        std::cout << "\033[2J\033[1;1H";
    }
}

void enterContinue() {
    std::cout << "Press enter to continue." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
T rng(const T &min, const T &max) {
    static std::random_device rd;
    static std::mt19937 rng(rd());
    std::uniform_int_distribution<T> dist(min, max);
    return dist(rng);
}
