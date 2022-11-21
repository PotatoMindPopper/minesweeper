#include "../include/table.h"
#include <cmath>

Table::Table() {
    // Do nothing
}

Table::Table(const int &height, const int &width) {
    // height and width - 1 because counting starts from 0
    if (height > 3 && width > 3) {
        this->height = height - 1;
        this->width = width - 1;
    } else {
        this->height = 0;
        this->width = 0;
    }

    this->tableEnd = std::make_shared<Cell>();
    this->tableEnd->x = this->width;
    this->tableEnd->y = this->height;
}

Table::Table(const int &height, const int &width, const float &percentage) {
    // height and width - 1 because counting starts from 0
    if (height > 3 && width > 3) {
        this->height = height - 1;
        this->width = width - 1;
    } else {
        this->height = 0;
        this->width = 0;
    }

    this->percentage = this->validPercentage(percentage);
    this->tableEnd = std::make_shared<Cell>();
    this->tableEnd->x = this->width;
    this->tableEnd->y = this->height;
}

Table::~Table() {
    debugMode = false;
    gameSetup = false;
    gameStarted = false;
    gameEnded = false;
    gameWon = false;
    showCell = false;
    markMines = false;
    showNeighbors = false;
    openNeighbors = false;

    height = -1;
    width = -1;
    mines = -1;
    flags = -1;
    opened = -1;
    highscore = -1;
    time = -1;

    percentage = -1;

    tableBegin.reset();
    tableBegin = nullptr;
    tableEnd.reset();
    tableEnd = nullptr;
}

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