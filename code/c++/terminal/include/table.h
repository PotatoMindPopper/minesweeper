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
        int mines{UNDEFINED};
        int flags{UNDEFINED};
        int opened{UNDEFINED};
        int highscore{UNDEFINED};
        int time{UNDEFINED};

        float percentage{UNDEFINED};

        CellSPtr table{nullptr};

        float validPercentage(const float &percentage);

        int validHeight(const int &height);
        int validWidth(const int &width);
    
};

#endif // __TABLE_H__