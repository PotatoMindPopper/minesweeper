#ifndef __BOARD_H__
#define __BOARD_H__

#include "constants.h"
#include <chrono>
#include <memory>
#include <stack>

typedef std::shared_ptr<struct Cell> CellSPtr;  // Cell in the board
typedef std::shared_ptr<class Board> BoardSPtr; // Stacked board
typedef std::unique_ptr<class Board> BoardUPtr; // Current board
typedef std::unique_ptr<class Stack> StackUPtr; // Stack of boards
typedef std::chrono::duration<float> Duration;  // Duration of the game
typedef std::chrono::time_point<std::chrono::system_clock> Time; // Time Point

// Constant for undefined duration
const Duration UNDEFINED_DURATION = std::chrono::duration<float>::zero();
// const Duration UNDEFINED_DURATION = std::chrono::duration<float>(0.0f);

// Constant for undefined time
// const Time UNDEFINED_TIME =
// std::chrono::time_point<std::chrono::system_clock>();
const Time UNDEFINED_TIME = std::chrono::system_clock::time_point();

/**
 * @brief A struct representing a single square on the board.
 */
struct Cell {
        // Properties
        enum class Type {
            MINE,                // Mine
            EMPTY,               // Empty cell
            UNDEFINED            // Undefined
        } type{Type::UNDEFINED}; // Type of the cell
        enum class State {
            HIDDEN,                // Hidden cell
            REVEALED,              // Revealed cell
            FLAG,                  // Flag
            QUESTION,              // Question mark
            UNDEFINED              // Undefined
        } state{State::UNDEFINED}; // State of the cell
        int value{UNDEFINED_INT};  // Value of the cell

        // Coordinates
        int x{UNDEFINED_INT}; // X coordinate
        int y{UNDEFINED_INT}; // Y coordinate

        // Pointers
        // List format:
        CellSPtr previous{nullptr}; // Previous cell in the board
        CellSPtr next{nullptr};     // Next cell in the board
        // Grid format:
        CellSPtr neighbours[8]{nullptr}; // Neighbours of the cell

        // Methods
        CellSPtr copy(const CellSPtr &cell);
        void reveal();
        void flag();
        void question();
};

/**
 * @brief A class representing the board.
 */
class Board {
        // Properties
        int width{UNDEFINED_INT};  // Width of the board (index: 0 to width-1)
        int height{UNDEFINED_INT}; // Height of the board (index: 0 to height-1)

        // Statistics at initialization
        struct Total {
                int mines_Total{UNDEFINED_INT};     // Number of mines
                int flags_Total{UNDEFINED_INT};     // Number of flags
                int revealed_Total{UNDEFINED_INT};  // Number of revealed cells
                int hidden_Total{UNDEFINED_INT};    // Number of hidden cells
                int cells_Total{UNDEFINED_INT};     // Total number of cells
                int questions_Total{UNDEFINED_INT}; // Number of question marks
        } total{UNDEFINED_INT};

        // Statistics during the game
        struct Left {
                int mines_Left{UNDEFINED_INT}; // Number of mines left
                int flags_Left{UNDEFINED_INT}; // Number of flags left
                int revealed_Left{
                    UNDEFINED_INT};             // Number of revealed cells left
                int hidden_Left{UNDEFINED_INT}; // Number of hidden cells left
                int cells_Left{UNDEFINED_INT};  // Total number of cells left
                int questions_Left{
                    UNDEFINED_INT}; // Number of question marks left
        } left{UNDEFINED_INT};

        // Min and max number of mines (based on the board size)
        int min_mines{UNDEFINED_INT};
        int max_mines{UNDEFINED_INT};

        float percentage{UNDEFINED_INT}; // Percentage of the mines

        // Pointers
        CellSPtr head{nullptr};    // Head of the board
        CellSPtr tail{nullptr};    // Tail of the board
        CellSPtr current{nullptr}; // Current cell

        // Status
        enum class Status {
            PLAYING,                 // Playing
            WON,                     // Won
            LOST,                    // Lost
            UNDEFINED                // Undefined
        } status{Status::UNDEFINED}; // Status of the game

    public:
        // Constructors
        Board(); // Default constructor
        Board(const int &width, const int &height,
              const int &percentage);  // Constructor
        Board(const BoardUPtr &board); // Copy constructor
        Board(const BoardSPtr &board); // Copy constructor

        // Destructor
        ~Board();

        // Operators
        template <typename T, typename U>
        T operator=(const U &board); // Assignment operator

        // Copy
        void copy(const BoardSPtr &board); // Copy the board
        void copy(const BoardUPtr &board); // Copy the board
        BoardSPtr deepCopy(const BoardSPtr &board) const;
        BoardUPtr shallowCopy(const BoardUPtr &board) const;
        void copyCells(const CellSPtr &head, const CellSPtr &tail,
                       const CellSPtr &current);  // Copy the cells
        CellSPtr copyCells(const CellSPtr &cell); // Copy the cells

        // Getters
        int getWidth() const;     // Get the width of the board
        int getHeight() const;    // Get the height of the board
        int getPerc() const;      // Get the percentage of the mines
        int getMines() const;     // Get the number of mines
        int getFlags() const;     // Get the number of flags
        int getRevealed() const;  // Get the number of revealed cells
        int getHidden() const;    // Get the number of hidden cells
        int getQuestions() const; // Get the number of question marks
        int getCells() const;     // Get the number of cells

        // Setters
        void setWidth(const int &width);   // Set the width of the board
        void setHeight(const int &height); // Set the height of the board
        void setPerc(const float &perc);   // Set the percentage of the mines
        void initialize();                 // Initialize the board

        // Status
        bool isPlaying() const;     // Check if the game is playing
        bool isWon() const;         // Check if the game is won
        bool isLost() const;        // Check if the game is lost
        Status getStatus() const;   // Get the status of the game
        char *getStatusStr() const; // Get the status of the game as a string

        // Board
        void create(); // Create the board
        void reset();  // Reset the board

        // Cells
        void reveal();   // Reveal the current cell
        void flag();     // Flag the current cell
        void question(); // Question the current cell

        // Neighbours
        void revealAll(); // Reveal all the cells
        void revealNeighbours(const int &x, const int &y);
        void
        revealNeighboursCurrent(); // Reveal the neighbours of the current cell

        // Navigation
        void next();   // Go to the next cell
        void prev();   // Go to the previous cell
        void first();  // Go to the first cell
        void last();   // Go to the last cell
        void random(); // Go to a random cell
        void coords(); // Go to the cell at coordinates

        // Print
        void print() const; // Print the board

        // Check
        void check() const; // Check the board, update the statistics and the
                            // status
        bool
        checkPerc(const float &perc); // Check if given perc is valid board wise
};

/**
 * @brief A class representing the game.
 */
class Stack {
        // Variables
        Time start_time{Time::min()};        // Start time
        Time end_time{Time::min()};          // End time
        Duration duration{Duration::zero()}; // Duration
        BoardUPtr current{nullptr};          // Current board
        std::stack<BoardSPtr> boards{};      // Stack of boards

        // Functions
        void push(BoardUPtr &&board); // Push a board to the stack
        BoardUPtr pop();              // Pop a board from the stack
        BoardUPtr &top();             // Get the top board
        bool empty();                 // Check if the stack is empty

    public:
        // Constructors
        Stack() = default;
        Stack(const Stack &) = delete;
        Stack(Stack &&) = delete;

        // Destructor
        ~Stack() = default;

        // Operators
        Stack &operator=(const Stack &) = delete;
        Stack &operator=(Stack &&) = delete;

        // Functions
        void menu();       // Menu
        void propagate();  // Propagate; set the menu execution
        void clockpulse(); // Clock pulse; process the menu execution
};

#endif // __BOARD_H__