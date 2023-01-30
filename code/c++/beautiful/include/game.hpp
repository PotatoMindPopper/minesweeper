#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "board.hpp"
#include "stack.hpp"
#include <chrono>

typedef std::chrono::duration<float> Duration;                   // Duration
typedef std::chrono::time_point<std::chrono::system_clock> Time; // Time

/**
 * @brief A class representing the game.
 */
class Game {

    BoardUPtr board;    // The board
    StackUPtr stack;    // The stack

    Time start;         // The start time
    Time end;           // The end time

    public:

};

#endif // __GAME_HPP__