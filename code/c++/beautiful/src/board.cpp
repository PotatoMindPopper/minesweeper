#include "board.hpp"
#include "exceptions.hpp"
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
    std::cout << "Percentage: " << this->percentage << std::endl;
}

/**
 * @brief Initialize the board
 * 
 * @param height The chosen height of the board
 * @param width  The chosen width of the board
 */
void Board::init(int height = DEFAULT_HEIGHT, int width = DEFAULT_WIDTH, 
                 float percentage = DEFAULT_PERCENTAGE) {
    this->setHeight(height);
    this->setWidth(width);
    this->setPercentage(percentage);
}

/**
 * @brief Set the height of the board
 * 
 * @param height The chosen height of the board
 */
void Board::setHeight(int height) {
    if (height < MIN_HEIGHT || height > MAX_HEIGHT)
        throw Out_Of_Height_Range(MIN_HEIGHT, MAX_HEIGHT);
    this->height = height;
}

/**
 * @brief Set the width of the board
 * 
 * @param width The chosen width of the board
 */
void Board::setWidth(int width) {
    if (width < MIN_WIDTH || width > MAX_WIDTH)
        throw Out_Of_Width_Range(MIN_WIDTH, MAX_WIDTH);
    this->width = width;
}

/**
 * @brief Set the percentage of mines
 * 
 * @param percentage The chosen percentage of mines
 */
void Board::setPercentage(float percentage) {
    if (percentage < MIN_PERCENTAGE || percentage > MAX_PERCENTAGE)
        throw Out_Of_Percentage_Range(MIN_PERCENTAGE, MAX_PERCENTAGE);
    this->percentage = percentage;
}
