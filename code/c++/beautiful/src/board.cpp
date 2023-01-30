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
    std::cout << "Percentage: " << this->percentage << std::endl;
}

/**
 * @brief Initialize the board
 * 
 * @param height The chosen height of the board
 * @param width  The chosen width of the board
 */
void Board::init(int height, int width, float percentage) {
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
    if (height < MIN_HEIGHT || height > MAX_HEIGHT) {
        this->height = DEFAULT_HEIGHT;
        std::cout << "Invalid height. Height must be between " << MIN_HEIGHT 
                  << " and " << MAX_HEIGHT << ". Defaulting to " 
                  << DEFAULT_HEIGHT << std::endl;
        return;
    }

    this->height = height;
}

/**
 * @brief Set the width of the board
 * 
 * @param width The chosen width of the board
 */
void Board::setWidth(int width) {
    if (width < MIN_WIDTH || width > MAX_WIDTH) {
        this->width = DEFAULT_WIDTH;
        std::cout << "Invalid width. Width must be between " << MIN_WIDTH 
                  << " and " << MAX_WIDTH << ". Defaulting to " 
                  << DEFAULT_WIDTH << std::endl;
        return;
    }

    this->width = width;
}

/**
 * @brief Set the percentage of mines
 * 
 * @param percentage The chosen percentage of mines
 */
void Board::setPercentage(float percentage) {
    if (percentage < MIN_PERCENTAGE || percentage > MAX_PERCENTAGE) {
        this->percentage = DEFAULT_PERCENTAGE;
        std::cout << "Invalid percentage. Percentage must be between " 
                  << MIN_PERCENTAGE << " and " << MAX_PERCENTAGE 
                  << ". Defaulting to " << DEFAULT_PERCENTAGE << std::endl;
        return;
    }

    this->percentage = percentage;
}
