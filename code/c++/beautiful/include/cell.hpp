#ifndef __CELL_HPP__
#define __CELL_HPP__

#include "constants.hpp"
#include <memory>

typedef std::shared_ptr<struct Cell> CellSPtr;     // Cell in the board

/**
 * @brief A struct representing a single square on the board.
 */
struct Cell {
    // Properties
    enum class Type {
        EMPTY,      // Empty cell
        MINE,       // Mine
        UNDEFINED,  // Undefined
        VALUED      // Valued cell
    } type{Type::UNDEFINED};    // Type of the cell
    enum class State {
        FLAG,       // Flag
        HIDDEN,     // Hidden cell
        QUESTION,   // Question mark
        REVEALED,   // Revealed cell
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

#endif // __CELL_HPP__