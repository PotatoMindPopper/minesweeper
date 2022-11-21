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

        void menu();

    private:
        bool gameSetup{false};
        bool gameStarted{false};
        bool gameEnded{false};
        bool gameWon{false};
        bool showCell{false};
        bool markMines{false};
        bool showNeighbors{false};
        bool openNeighbors{false};

        int height{-1};
        int width{-1};
        int mines{-1};
        int flags{-1};
        int opened{-1};
        int highscore{-1};
        int time{-1};

        float percentage{-1};

        CellSPtr table{nullptr};

        float validPercentage(const float &percentage);
    
        void newGame();
        void options();
        void playGame();

};

#endif // __TABLE_H__