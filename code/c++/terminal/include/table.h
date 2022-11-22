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

    private:
        bool gameSetup{false};
        bool gameStarted{false};
        bool gameEnded{false};
        bool gameWon{false};
        bool showCell{false};
        bool markMines{false};
        bool showNeighbors{false};
        bool openNeighbors{false};

        int height{UNDEFINED};
        int width{UNDEFINED};
        int min_mines{UNDEFINED};
        int max_mines{UNDEFINED};
        int mines{UNDEFINED};
        int flags{UNDEFINED};
        int opened{UNDEFINED};
        int highscore{UNDEFINED};
        int time{UNDEFINED};

        float percentage{UNDEFINED};

        CellSPtr table{nullptr};

        float validPercentage(const float &percentage);
        float percent_mines() const;

        int validHeight(const int &height);
        int validWidth(const int &width);

        void set_mines_limit();
        void set_mines(const int &input);
    
};

#endif // __TABLE_H__