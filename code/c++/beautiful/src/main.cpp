#include "board.hpp"
#include <iostream>

int main() {
    BoardUPtr board = std::make_unique<Board>();
    std::cout << "Hello, world!" << std::endl;
    board->init(40, 10, 0.2);
    std::cout << "Board initialized" << std::endl;
    board->print();
    return 0;
}
