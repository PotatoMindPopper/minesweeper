#ifndef __CELL_H__
#define __CELL_H__

#include <memory>

typedef std::shared_ptr<class Cell> CellSPtr;

struct Cell {
    bool mine{false};
    bool opened{false};
    bool flagged{false};

    // Coordinates, based on the grid of the table.
    int x{UNDEFINED_INT};
    int y{UNDEFINED_INT};
    int neighbors_mines{UNDEFINED_INT};

    // Neighbor to the right
    // If end of row is reached, next is beginning of next row.
    CellSPtr next{UNDEFINED_PTR};

    // Neighbor to the left
    // If beginning of row is reached, prev is end of previous row.
    CellSPtr prev{UNDEFINED_PTR};

    // 0: up
    // 1: up_right
    // 2: right
    // 3: down_right
    // 4: down
    // 5: down_left
    // 6: left
    // 7: up_left
    CellSPtr neighbors[8]{UNDEFINED_PTR};
};

#endif // __CELL_H__