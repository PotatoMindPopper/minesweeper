#ifndef __TABLE_H__
#define __TABLE_H__

#include "standard.h"
#include "constants.h"
#include "cell.h"
#include "constants_with_includes.h"
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

        TableSPtr deepCopy() const;
        TableUPtr shallowCopy() const;

    private:
        bool gameWon{false};        // True if the game has been won.
        bool showCell{false};       // Use as clockpulse; set in propagate / processMenu
        bool markMine{false};       // Set in propagate / processMenu
        bool gameSetup{false};      // Set in newGame
        bool gameEnded{false};      // Set in propagate / processMenu
        bool gameStarted{false};    // Set in propagate / processMenu
        bool showNeighbors{false};  // Set in propagate / processMenu
        bool openNeighbors{false};  // Set in propagate / processMenu

        int time{UNDEFINED_INT};        // Time elapsed in int seconds
        int flags{UNDEFINED_INT};       // Number of flags placed
        int width{UNDEFINED_INT};       // Number of columns
        int height{UNDEFINED_INT};      // Number of rows
        int opened{UNDEFINED_INT};      // Number of cells opened
        int min_mines{UNDEFINED_INT};   // Minimum number of mines
        int max_mines{UNDEFINED_INT};   // Maximum number of mines
        int highscore{UNDEFINED_INT};   // Highscore
        int totalMines{UNDEFINED_INT};  // Number of mines in the table
        int totalFlags{UNDEFINED_INT};  // Number of flags to be placed

        float percentage{UNDEFINED_INT};    // Percentage of mines

        CellSPtr table{UNDEFINED_PTR};    // Pointer to the table

        TimePoint startTime{UNDEFINED_TIME};    // Start time
        TimePoint endTime{UNDEFINED_TIME};      // End time
        TimePoint currentTime{UNDEFINED_TIME};  // Current time

        Duration duration{UNDEFINED_DURATION};  // Duration of the game

        float percent_mines() const;
        float validPercentage(const float &percentage);

        int getWidth();
        int getHeight();
        int validWidth(const int &width);
        int validHeight(const int &height);
        int getPercentage();

        void createGrid();
        void set_mines_limit();
        void placeMines() const;
        void setNeighbors() const;
        void set_mines(const int &input);
        void setNeighbors(const CellSPtr &cell) const;

        CellSPtr copyTable() const;
        CellSPtr copyCell(const CellSPtr &cell) const;
        CellSPtr getCellFor(const int &x, const int &y) const;
        CellSPtr getCellWhile(const int &x, const int &y) const;
        CellSPtr getCellRec(const int &x, const int &y, const CellSPtr &cell) const;

};

#endif // __TABLE_H__