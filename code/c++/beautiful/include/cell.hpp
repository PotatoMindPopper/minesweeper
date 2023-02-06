#ifndef __CELL_HPP__
#define __CELL_HPP__

#include "constants.hpp"
#include <memory>
#include <string>

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

    // Methods
    std::string to_string();            // Convert the cell values to a string
    std::string to_string(Type type);   // Convert the type to a string
    std::string to_string(State state); // Convert the state to a string
    void change_type(int value);        // Change the type of the cell
    void change_state(int value);       // Change the state of the cell
    void flag();                        // Flag the cell
    void reveal();                      // Reveal the cell
    void question();                    // Question the cell
}; // struct Cell

#endif // __CELL_HPP__