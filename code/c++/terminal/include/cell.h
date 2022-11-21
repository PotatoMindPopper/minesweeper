#ifndef __CELL_H__
#define __CELL_H__

struct Cell {
    bool opened{false};
    bool flagged{false};
    bool mine{false};

    int x{0};
    int y{0};

    Cell *next{nullptr};
    Cell *prev{nullptr};

    Cell *up{nullptr};
    Cell *down{nullptr};
    Cell *left{nullptr};
    Cell *right{nullptr};
    Cell *up_left{nullptr};
    Cell *up_right{nullptr};
    Cell *down_left{nullptr};
    Cell *down_right{nullptr};
    // OR
    Cell *neighbors[8]{nullptr};
};

#endif // __CELL_H__