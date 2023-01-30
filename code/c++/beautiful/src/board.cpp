#include "board.hpp"
#include <iostream>

/**
 * @brief Construct a new Board:: Board object
 * 
 */
Board::Board() {
    this->height = DEFAULT_HEIGHT;
    this->width = DEFAULT_WIDTH;
}

/**
 * @brief Construct a new Board:: Board object
 * 
 * @param height The chosen height of the board
 * @param width  The chosen width of the board
 */
Board::Board(int height, int width) {
    this->height = height;
    this->width = width;
}

/**
 * @brief Destroy the Board:: Board object
 * 
 */
Board::~Board() {
    // Nothing to do
}

void Board::print() {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "Height: " << this->height << std::endl;
    std::cout << "Width: " << this->width << std::endl;
}
