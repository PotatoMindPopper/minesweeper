#include "board.hpp"
#include <iostream>

/**
 * @brief Construct a new Board:: Board object
 * 
 */
Board::Board() {
    // Nothing to do
}

/**
 * @brief Destroy the Board:: Board object
 * 
 */
Board::~Board() {
    // Nothing to do
}

/**
 * @brief Print the board
 * 
 */
void Board::print() {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            std::cout << ".";
        }
        std::cout << std::endl;
    }
    
    std::cout << "Height: " << this->height << std::endl;
    std::cout << "Width: " << this->width << std::endl;
}

/**
 * @brief Initialize the board
 * 
 * @param height The chosen height of the board
 * @param width  The chosen width of the board
 */
void Board::init(int height, int width) {
    if (height < MIN_HEIGHT || height > MAX_HEIGHT)
        return;
    if (width < MIN_WIDTH || width > MAX_WIDTH)
        return;
    this->height = height;
    this->width = width;
}
