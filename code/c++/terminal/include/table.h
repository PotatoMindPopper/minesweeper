#ifndef __TABLE_H__
#define __TABLE_H__

#include "standard.h"
#include "constants.h"
#include "cell.h"
#include <memory>

typedef std::unique_ptr<class Table> TableUPtr;
typedef std::shared_ptr<class Table> TableSPtr;

class Table {
    public:
        Table();
        ~Table();

        void newGame();
        void options();
        void playGame();

        TableSPtr deepCopy();
        TableUPtr shallowCopy();

    private:
        bool gameSetup{false};
        bool gameStarted{false};
        bool gameEnded{false};
        bool gameWon{false};
        bool showCell{false};       // Use as clockpulse
        bool markMine{false};       // Set in propagate / processMenu
        bool showNeighbors{false};
        bool openNeighbors{false};

        int height{UNDEFINED_INT};
        int width{UNDEFINED_INT};
        int min_mines{UNDEFINED_INT};
        int max_mines{UNDEFINED_INT};
        int mines{UNDEFINED_INT};
        int flags{UNDEFINED_INT};
        int opened{UNDEFINED_INT};
        int highscore{UNDEFINED_INT};
        int time{UNDEFINED_INT};

        float percentage{UNDEFINED_INT};

        CellSPtr table{nullptr};

        float validPercentage(const float &percentage);
        float percent_mines() const;

        int validHeight(const int &height);
        int validHeight();
        int validWidth(const int &width);
        int validWidth();

        void set_mines_limit();
        void set_mines(const int &input);

        CellSPtr copyTable() const;
        CellSPtr copyCell(const CellSPtr &cell) const;

};

#endif // __TABLE_H__