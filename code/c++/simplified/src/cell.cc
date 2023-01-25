#include "board.h"
#include "standard.h"

/**
 * @brief Copy the cell.
 *
 * @param CellSPtr The cell to copy.
 * @return CellSPtr The copied cell.
 */
CellSPtr Cell::copy(const CellSPtr &cell) {
    // Create a new cell
    CellSPtr newCell = std::make_shared<Cell>();

    // Copy the cell
    newCell->x = cell->x;
    newCell->y = cell->y;
    newCell->value = cell->value;
    newCell->state = cell->state;
    newCell->type = cell->type;
    newCell->next = this->copy(cell->next);
    newCell->previous = this->copy(cell->previous);
    for (int i = 0; i < 8; i++) {
        newCell->neighbours[i] = this->copy(cell->neighbours[i]);
    }

    // Return the new cell
    return newCell;
}

/**
 * @brief Reveal the cell.
 */
void Cell::reveal() { this->state = State::REVEALED; }

/**
 * @brief Flag the cell.
 */
void Cell::flag() { this->state = State::FLAG; }

/**
 * @brief Question the cell.
 */
void Cell::question() { this->state = State::QUESTION; }