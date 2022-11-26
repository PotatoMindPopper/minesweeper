#include "random.h"
#include <random>

/**
 * @brief Randomly generate a number between min and max.
 * 
 * @param min The minimum number to generate.
 * @param max The maximum number to generate.
 * @return int The randomly generated number.
 */
int randNT(const int &min, const int &max) {
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

/**
 * @brief Randomly generate a number between min and max.
 * 
 * Uses the C++11 random library.
 * 
 * @param min The minimum number to generate.
 * @param max The maximum number to generate.
 * @return int The randomly generated number.
 */
int randN(const int &min, const int &max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(mt);
}
