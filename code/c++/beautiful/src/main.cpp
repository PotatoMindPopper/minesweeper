#include "board.hpp"
#include <iostream>

int main() {
    BoardUPtr board = std::make_unique<Board>();
    // board->init(4, 5);
    board->print();
    return 0;
}