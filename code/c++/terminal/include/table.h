#ifndef __TABLE_H__
#define __TABLE_H__

#include "cell.h"
#include <memory>

typedef std::unique_ptr<class Table> TableUPtr;
typedef std::shared_ptr<class Table> TableSPtr;

class Table {
    public:
        Table();
        Table(const int &height, const int &width);
        Table(const int &height, const int &width, const int &mines);
        ~Table();

    private:
        int height{0};
        int width{0};
        int mines{0};

        CellSPtr table{nullptr};
    
};

#endif // __TABLE_H__