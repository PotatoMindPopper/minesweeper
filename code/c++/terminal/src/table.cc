#include "../include/table.h"
#include <cmath>
#include <iostream>

Table::Table() {
    // Do nothing
}

Table::~Table() {
    table = nullptr;
}












/**
 * @brief Checks if the given height is a valid height.
 * 
 * @param height 
 * @return int 
 */
int Table::validHeight(const int &height) {
    if (height > MAX_HEIGHT) {
        return MAX_HEIGHT;
    } else if (height < MIN_HEIGHT) {
        return MIN_HEIGHT;
    } else {
        return height;
    }
}

/**
 * @brief Checks if the given width is a valid width.
 * 
 * @param width 
 * @return int 
 */
int Table::validWidth(const int &width) {
    if (width > MAX_WIDTH) {
        return MAX_WIDTH;
    } else if (width < MIN_WIDTH) {
        return MIN_WIDTH;
    } else {
        return width;
    }
}



/**
 * @brief Checks if the given percentage is a valid percentage.
 * 
 * @param percentage 
 * @return float 
 */
float Table::validPercentage(const float &percentage) {
    int size = (this->height + 1) * (this->width + 1);
    int max_mines = (int) round((float)100.0 * (float)(size - 10) / size);
    int min_mines = (int) fmax(1, (int) round((float)100.0 / size));

    if (percentage > max_mines) {
        return max_mines;
    } else if (percentage < min_mines) {
        return min_mines;
    } else {
        return percentage;
    }
}

/**
 * @brief Sets the bounds for the mines.
 * 
 */
void Table::set_mines_limit() {
    int size = (this->height + 1) * (this->width + 1);
    int max_mines = (int) round(100.0f * (float)(size - 10) / size);
    int min_mines = (int) fmax(1, (int) round(100.0f / size));
    this->min_mines = min_mines;
    this->max_mines = max_mines;
    this->percentage = (int) round(this->percent_mines());
}

/**
 * @brief Calculates the percentage of mines on the given grid.
 * 
 * @return float 
 */
float Table::percent_mines() const {
    return 100.0f * (float)this->mines / (this->height + 1) * (this->width + 1);
}

/**
 * @brief Sets the amount of mines to be put into the table.
 * 
 * @param input 
 */
void Table::set_mines(const int &input) {
    if (fabs(percent_mines() - input) <= 0.5f)
        return;

    this->mines = (int) round(input * ((this->width + 1) * (this->height + 1)) / 100.0f);
}





/**
 * @brief Initialize a new game.
 * 
 */
void Table::newGame() {

    std::cout << "Enter the height of the table: ";
    std::cin >> this->height;
    this->height = validHeight(this->height);

    std::cout << "Enter the width of the table: ";
    std::cin >> this->width;
    this->width = validWidth(this->width);

    std::cout << "Enter the percentage of mines: ";
    std::cin >> this->percentage;
    this->percentage = validPercentage(this->percentage);

    this->mines = (int) round((float)this->percentage * (float)(this->height + 1) * (float)(this->width + 1) / 100.0);
    this->flags = this->mines;
    this->opened = 0;



}