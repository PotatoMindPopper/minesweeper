#include "../include/table.h"
#include <cmath>

Table::Table() {
    // Do nothing
}

Table::~Table() {
    table = nullptr;
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

int Table::validHeight(const int &height) {
    if (height > MAX_HEIGHT) {
        return MAX_HEIGHT;
    } else if (height < MIN_HEIGHT) {
        return MIN_HEIGHT;
    } else {
        return height;
    }
}

int Table::validWidth(const int &width) {
    if (width > MAX_WIDTH) {
        return MAX_WIDTH;
    } else if (width < MIN_WIDTH) {
        return MIN_WIDTH;
    } else {
        return width;
    }
}