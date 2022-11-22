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
 * @brief Get the user input for the height of the table
 * 
 * @return int The height of the table
 */
int Table::validHeight() {
    std::cout << "Enter the height of the table: ";
    int height;
    std::cin >> height;
    if (height < MIN_HEIGHT) {
        std::cout << "Height must be at least " << MIN_HEIGHT << std::endl;
        return validHeight();
    } else if (height > MAX_HEIGHT) {
        std::cout << "Height must be at most " << MAX_HEIGHT << std::endl;
        return validHeight();
    } else {
        return height;
    }
}

/**
 * @brief Get the user input for the width of the table
 * 
 * @return int The width of the table
 */
int Table::validWidth() {
    std::cout << "Enter the width of the table: ";
    int width;
    std::cin >> width;
    while (true) {
        if (width > MAX_WIDTH) {
            std::cout << "Invalid width: " << width << std::endl;
            std::cout << "Width must be less then " << MAX_WIDTH << std::endl;
        } else if (width < MIN_WIDTH) {
            std::cout << "Invalid width: " << width << std::endl;
            std::cout << "Width must be greater than " << MIN_WIDTH << std::endl;
        } else {
            std::cout << "Width is set to " << width << std::endl;
            return width;
        }
        std::cout << "Enter a new width: ";
        std::cin >> width;
    }
}

/**
 * @brief Initialize a new game.
 * 
 */
void Table::newGame() {

    // Set grid height;
    this->height = this->validHeight();

    // Set grid width;
    this->width = this->validWidth();

    // Set min and max mines;
    int gridSize = (this->height + 1) * (this->width + 1);
    this->min_mines = (int) round(100.0f * ((float)(gridSize - 10) / gridSize));
    this->max_mines = (int) fmax(1, (int) round(100.0f / gridSize));

    // Set user mines percentage;
    int iPerc{UNDEFINED_INT};
    std::cout << "Enter the percentage of mines: ";
    std::cin >> iPerc;



    // Check if iPerc is valid, within the grid bounds;

    // If precent_mines is already within the given input and predetermined small value.
    if (fabs(this->percentage - iPerc) <= 0.5f) {;}



    this->mines = (int) round((float)this->percentage * (float)(this->height + 1) * (float)(this->width + 1) / 100.0f);
    this->flags = this->mines;
    this->opened = 0;



}

/**
 * @brief Make a shallow copy of the table handler, all pointers are copied.
 * 
 * @return TableUPtr 
 */
TableUPtr Table::shallowCopy() {
    TableUPtr copy = std::make_unique<Table>();
    copy->gameSetup = this->gameSetup;
    copy->gameStarted = this->gameStarted;
    copy->gameEnded = this->gameEnded;
    copy->gameWon = this->gameWon;
    copy->showCell = this->showCell;
    copy->markMine = this->markMine;
    copy->showNeighbors = this->showNeighbors;
    copy->openNeighbors = this->openNeighbors;
    copy->height = this->height;
    copy->width = this->width;
    copy->min_mines = this->min_mines;
    copy->max_mines = this->max_mines;
    copy->mines = this->mines;
    copy->flags = this->flags;
    copy->opened = this->opened;
    copy->highscore = this->highscore;
    copy->time = this->time;
    copy->percentage = this->percentage;
    copy->table = this->copyCell(this->table);
    return copy;
}

/**
 * @brief Make a deep copy of the table handler.
 * 
 * @return TableSPtr 
 */
TableSPtr Table::deepCopy() {
    TableSPtr copy = std::make_shared<Table>();
    copy->gameSetup = this->gameSetup;
    copy->gameStarted = this->gameStarted;
    copy->gameEnded = this->gameEnded;
    copy->gameWon = this->gameWon;
    copy->showCell = this->showCell;
    copy->markMine = this->markMine;
    copy->showNeighbors = this->showNeighbors;
    copy->openNeighbors = this->openNeighbors;
    copy->height = this->height;
    copy->width = this->width;
    copy->min_mines = this->min_mines;
    copy->max_mines = this->max_mines;
    copy->mines = this->mines;
    copy->flags = this->flags;
    copy->opened = this->opened;
    copy->highscore = this->highscore;
    copy->time = this->time;
    copy->percentage = this->percentage;
    copy->table = this->copyCell(this->table);
    return copy;
}

/**
 * @brief Copy a cell object/pointer.
 * 
 * @param table The pointer to the cell to copy.
 * @return CellSPtr 
 */ 
CellSPtr Table::copyCell(const CellSPtr &cell) const {

    if (!cell) {
        return nullptr;
    }

    CellSPtr newCell = std::make_shared<Cell>();

    newCell->mine = cell->mine;
    newCell->flagged = cell->flagged;
    newCell->opened = cell->opened;
    newCell->x = cell->x;
    newCell->y = cell->y;

    newCell->next = this->copyCell(cell->next);
    newCell->prev = this->copyCell(cell->prev);

    for (int i = 0; i < 8; i++) {
        newCell->neighbors[i] = this->copyCell(cell->neighbors[i]);
    }

    newCell->up = this->copyCell(cell->up);
    newCell->down = this->copyCell(cell->down);
    newCell->left = this->copyCell(cell->left);
    newCell->right = this->copyCell(cell->right);
    newCell->up_left = this->copyCell(cell->up_left);
    newCell->up_right = this->copyCell(cell->up_right);
    newCell->down_left = this->copyCell(cell->down_left);
    newCell->down_right = this->copyCell(cell->down_right);

    return newCell;
}

/**
 * @brief Copy the table object/pointer.
 * 
 * @return CellSPtr 
 */ 
CellSPtr Table::copyTable() const {
    return this->copyCell(this->table);
}