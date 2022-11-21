#ifndef __CELL_H__
#define __CELL_H__

#include <memory>

typedef std::shared_ptr<class Cell> CellSPtr;

struct Cell {
    bool mine{false};
    bool opened{false};
    bool flagged{false};

    int x{0};
    int y{0};

    CellSPtr next{nullptr};
    CellSPtr prev{nullptr};

    CellSPtr neighbors[8]{nullptr};
    // OR
    CellSPtr up{neighbors[0]};
    CellSPtr up_right{neighbors[1]};
    CellSPtr right{neighbors[2]};
    CellSPtr down_right{neighbors[3]};
    CellSPtr down{neighbors[4]};
    CellSPtr down_left{neighbors[5]};
    CellSPtr left{neighbors[6]};
    CellSPtr up_left{neighbors[7]};
};

#endif // __CELL_H__