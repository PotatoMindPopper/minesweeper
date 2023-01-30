#include "board.hpp"
#include "exceptions.hpp"
#include <iostream>

int main() {
    BoardUPtr board = std::make_unique<Board>();
    try {
        board->init(40, 10);
    } catch (Invalid_Height& e) {
        std::cout << e.what() << std::endl;
        std::cout << "Height must be between " << MIN_HEIGHT << " and " 
                  << MAX_HEIGHT << std::endl;
        std::cout << "Setting height to " << DEFAULT_HEIGHT << std::endl;
        board->setHeight(DEFAULT_HEIGHT);
    } catch (Invalid_Width& e) {
        std::cout << e.what() << std::endl;
        std::cout << "Width must be between " << MIN_WIDTH << " and " 
                  << MAX_WIDTH << std::endl;
        std::cout << "Setting width to " << DEFAULT_WIDTH << std::endl;
        board->setWidth(DEFAULT_WIDTH);
    }
    board->print();
    return 0;
}
