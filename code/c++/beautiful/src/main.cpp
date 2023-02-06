#include "board.hpp"
#include "constants.hpp"
#include <iostream>

int main() {
    std::cout << "Cell" << std::endl;
    CellSPtr cell = std::make_shared<Cell>();
    std::cout << "Hello, world!" << std::endl;
    cell->type = Cell::Type::MINE;
    cell->state = Cell::State::FLAG;
    cell->value = UNDEFINED_INT;
    cell->x = 1;
    cell->y = 2;
    std::cout << "Cell initialized" << std::endl;
    std::cout << cell->to_string() << std::endl;

    std::cout << "Board" << std::endl;
    BoardUPtr board = std::make_unique<Board>();
    std::cout << "Hello, world!" << std::endl;
    board->init(40, 10, 0.2);
    if (!board->isInitialized()) {
        std::cout << "Board not initialized" << std::endl;
        return 1;
    }
    std::cout << "Board initialized" << std::endl;
    board->print();

    return 0;
}
