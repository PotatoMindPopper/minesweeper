#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include "cell.hpp"
#include "constants.hpp"
#include <memory>

typedef std::shared_ptr<class Board> BoardSPtr;    // Stacked board
typedef std::unique_ptr<class Board> BoardUPtr;    // Currect board

/**
 * @brief A class representing the board.
 */
class Board {

    int height{DEFAULT_HEIGHT}; // Height of the board
    int width{DEFAULT_WIDTH};   // Width of the board

    public:

        Board();    // Constructor
        ~Board();   // Destructor

        void print();                       // Print the board
        void init(int height, int width);   // Initialize the board

        void setHeight(int height); // Set the height of the board
        void setWidth(int width);   // Set the width of the board

};

#endif // __BOARD_HPP__