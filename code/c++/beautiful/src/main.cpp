#include "board.hpp"
#include "exceptions.hpp"
#include <iostream>

int main() {
    BoardUPtr board = std::make_unique<Board>();
    try {
        board->init(50, 40, 0.1);
    } catch (const Out_Of_Height_Range& e) {
        std::cout << e.what() << std::endl;
    } catch (const Out_Of_Width_Range& e) {
        std::cout << e.what() << std::endl;
    } catch (const Out_Of_Percentage_Range& e) {
        std::cout << e.what() << std::endl;
    }
    board->print();
    return 0;
}
