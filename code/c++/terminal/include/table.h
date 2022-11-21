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
        Table(const int &height, const int &width);
        Table(const int &height, const int &width, const float &percentage);
        ~Table();

        void newGame();
        void loadGame();
        void saveGame();
        void showHighscoreTable();
        void options();
        void playGame();

    private:
        bool debugMode{false};
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

        CellSPtr tableBegin{nullptr};
        CellSPtr tableEnd{nullptr};


        float validPercentage(const float &percentage);
    
};

#endif // __TABLE_H__