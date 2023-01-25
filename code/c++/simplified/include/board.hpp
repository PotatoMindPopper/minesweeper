#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include "constants.hpp"
#include <memory>
#include <chrono>

typedef std::shared_ptr<struct Cell> CellSPtr;     // Cell in the board
typedef std::shared_ptr<class Board> BoardSPtr;    // Stacked board
typedef std::unique_ptr<class Board> BoardUPtr;    // Currect board
typedef std::unique_ptr<class Stack> StackUPtr;    // Stack of boards
typedef std::chrono::duration<float> Duration;     // Duration
typedef std::chrono::time_point<std::chrono::system_clock> Time; // Time

/**
 * @brief A struct representing a single square on the board.
 */
struct Cell {
    // Properties
    enum class Type {
        MINE,       // Mine
        EMPTY,      // Empty cell
        UNDEFINED   // Undefined
    } type{Type::UNDEFINED};    // Type of the cell
    enum class State {
        HIDDEN,     // Hidden cell
        REVEALED,   // Revealed cell
        FLAG,       // Flag
        QUESTION,   // Question mark
        UNDEFINED   // Undefined
    } state{State::UNDEFINED};  // State of the cell
    int value{UNDEFINED_INT};   // Value of the cell

    // Coordinates
    int x{UNDEFINED_INT};  // X coordinate
    int y{UNDEFINED_INT};  // Y coordinate

    // Pointers
    // List format:
    CellSPtr previous{nullptr};     // Previous cell in the board
    CellSPtr next{nullptr};         // Next cell in the board
    // Grid format:
    CellSPtr neighbors[8]{nullptr}; // Neighbors of the cell
};

/**
 * @brief A class representing the board.
 */
class Board {

    public:

};

/**
 * @brief A class representing the game.
 */
class Stack {

    public:

};

#endif // __BOARD_H__