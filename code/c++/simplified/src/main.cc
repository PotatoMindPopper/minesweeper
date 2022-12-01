#include "board.h"
#include <iostream>

void information();

int main() {
    information();
    StackUPtr stack = std::make_unique<Stack>();
    stack->menu();
    stack.reset();
    return 0;
}

void information() {
    std::cout << "Welcome to the Minesweeper game!" << std::endl;
    std::cout << "The goal of the game is to reveal all the cells that do not contain a mine." << std::endl;
    std::cout << "The game ends when all the mines are flagged or when a cell containing a mine is revealed." << std::endl;
    std::cout << "The game can be played in two modes: standard and custom." << std::endl;
    std::cout << "In the standard mode, the board is 10x10 and 30% of the cells contain a mine." << std::endl;
    std::cout << "In the custom mode, the user can choose the size of the board and the percentage of the mines." << std::endl;
    std::cout << "The user can reveal a cell by pressing 'r' and then the coordinates of the cell." << std::endl;
    std::cout << "The user can flag a cell by pressing 'f' and then the coordinates of the cell." << std::endl;
    std::cout << "The user can remove a flag by pressing 'f' and then the coordinates of the cell." << std::endl;
    std::cout << "The user can place a question mark by pressing 'e' and then the coordinates of the cell." << std::endl;
    std::cout << "The user can remove a question mark by pressing 'e' and then the coordinates of the cell." << std::endl;
    std::cout << "The user can move the cursor by pressing 'w', 'a', 's' or 'd'." << std::endl;
    std::cout << "The user can quit the game by pressing 'q'." << std::endl;
    std::cout << "The user can save the game by pressing 'p'." << std::endl;
    std::cout << "The user can load the game by pressing 'o'." << std::endl;
    std::cout << "The user can start a new game by pressing 'n'." << std::endl;
    std::cout << "The user can see the instructions by pressing 'h'." << std::endl;
    std::cout << "The user can see the statistics by pressing 't'." << std::endl;
    std::cout << "The user can see the best times by pressing 'b'." << std::endl;
    std::cout << "The user can see the best scores by pressing 's'." << std::endl;

    std::cout << std::endl;

    std::cout << "The game is played on a board of cells." << std::endl;
    std::cout << "Each cell is either empty or contains a mine." << std::endl;
    std::cout << "The user can reveal a cell by pressing 'r' and then the coordinates of the cell." << std::endl;
    std::cout << "If the cell contains a mine, the game ends." << std::endl;
    std::cout << "If the cell does not contain a mine, the cell is revealed and the number of mines in the neighboring cells is displayed." << std::endl;
    std::cout << "If the cell does not contain a mine and has no neighboring mines, all the neighboring cells are revealed." << std::endl;
    std::cout << "The user can flag a cell by pressing 'f' and then the coordinates of the cell." << std::endl;
    std::cout << "The user can remove a flag by pressing 'f' and then the coordinates of the cell." << std::endl;
    std::cout << "The user can place a question mark by pressing 'e' and then the coordinates of the cell." << std::endl;
    std::cout << "The user can remove a question mark by pressing 'e' and then the coordinates of the cell." << std::endl;
    std::cout << "The user can move the cursor by pressing 'w', 'a', 's' or 'd'." << std::endl;
    std::cout << "The user can quit the game by pressing 'q'." << std::endl;
    std::cout << "The user can save the game by pressing 'p'." << std::endl;
    std::cout << "The user can load the game by pressing 'o'." << std::endl;
    std::cout << "The user can start a new game by pressing 'n'." << std::endl;
    std::cout << "The user can see the instructions by pressing 'h'." << std::endl;
    std::cout << "The user can see the statistics by pressing 't'." << std::endl;
    std::cout << "The user can see the best times by pressing 'b'." << std::endl;
    std::cout << "The user can see the best scores by pressing 's'." << std::endl;

    std::cout << std::endl;
}