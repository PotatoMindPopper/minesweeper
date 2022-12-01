#include "board.h"
#include "standard.h"

/**
 * @brief Construct a new Board:: Board object
 */
Board::Board() {
    this->width = DEFAULT_WIDTH;
    this->height = DEFAULT_HEIGHT;
    this->percentage = DEFAULT_PERCENTAGE;
    // Initialize the board
    this->initialize();
}

/**
 * @brief Construct a new Board:: Board object
 *
 * @param width Width of the board
 * @param height Height of the board
 * @param percentage Percentage of the mines
 */
Board::Board(const int &width, const int &height, const int &percentage) {
    this->width = width;
    this->height = height;
    this->percentage = percentage;
    // Initialize the board
    this->initialize();
}

/**
 * @brief Construct a new Board:: Board object
 *
 * @param board Board to copy
 */
Board::Board(const Board &board)
    : width(board.width), height(board.height), percentage(board.percentage),
      mines_Total(board.mines_Total), mines_Left(board.mines_Left),
      flags_Total(board.flags_Total), flags_Left(board.flags_Left),
      questions_Total(board.questions_Total),
      questions_Left(board.questions_Left),
      revealed_Total(board.revealed_Total), revealed_Left(board.revealed_Left),
      hidden_Total(board.hidden_Total), hidden_Left(board.hidden_Left),
      cells_Total(board.cells_Total), cells_Left(board.cells_Left),
      min_mines(board.min_mines), max_mines(board.max_mines),
      status(board.status) {
    // Copy the board
    this->copy(board);
}

/**
 * @brief Construct a new Board:: Board object
 *
 * @param board Board to move
 */
Board::Board(Board &&board) noexcept
    : width(board.width), height(board.height), percentage(board.percentage),
      mines_Total(board.mines_Total), mines_Left(board.mines_Left),
      flags_Total(board.flags_Total), flags_Left(board.flags_Left),
      questions_Total(board.questions_Total),
      questions_Left(board.questions_Left),
      revealed_Total(board.revealed_Total), revealed_Left(board.revealed_Left),
      hidden_Total(board.hidden_Total), hidden_Left(board.hidden_Left),
      cells_Total(board.cells_Total), cells_Left(board.cells_Left),
      min_mines(board.min_mines), max_mines(board.max_mines),
      status(board.status) {
    // Move the board
    this->move(std::move(board));
}

/**
 * @brief Destroy the Board:: Board object
 */
Board::~Board() {
    // Delete the cells
    this->head = nullptr;
    this->tail = nullptr;
    this->current = nullptr;
}

/**
 * @brief Copy assignment operator
 *
 * @param board Board to copy
 * @return Board& Reference to the board
 */
Board &Board::operator=(const Board &board) {
    // Check for self-assignment
    if (this != &board) {
        // Copy the board
        this->copy(board);
    }
    return *this;
}

/**
 * @brief Move assignment operator
 *
 * @param board Board to move
 * @return Board& Reference to the board
 */
Board &Board::operator=(Board &&board) noexcept {
    // Check for self-assignment
    if (this != &board) {
        // Move the board
        this->move(std::move(board));
    }
    return *this;
}

/**
 * @brief Unique pointer assignment operator
 *
 * @param board Board to copy
 * @return BoardUPtr& Reference to the board
 */
BoardUPtr Board::operator=(BoardUPtr &board) {
    // Check for self-assignment
    if (this != board.get()) {
        // Copy the board
        this->copy(*board);
    }
    return std::move(board);
}

/**
 * @brief Unique pointer assignment operator
 *
 * @param board Board to move
 * @return BoardUPtr& Reference to the board
 */
BoardUPtr Board::operator=(BoardUPtr &&board) noexcept {
    // Check for self-assignment
    if (this != board.get()) {
        // Move the board
        this->move(std::move(*board));
    }
    return std::move(board);
}

/**
 * @brief Shared pointer assignment operator
 *
 * @param board Board to copy
 * @return BoardSPtr& Reference to the board
 */
BoardSPtr Board::operator=(BoardSPtr &board) {
    // Check for self-assignment
    if (this != board.get()) {
        // Copy the board
        this->copy(*board);
    }
    return std::move(board);
}

/**
 * @brief Shared pointer assignment operator
 *
 * @param board Board to move
 * @return BoardSPtr& Reference to the board
 */
BoardSPtr Board::operator=(BoardSPtr &&board) noexcept {
    // Check for self-assignment
    if (this != board.get()) {
        // Move the board
        this->move(std::move(*board));
    }
    return std::move(board);
}

/**
 * @brief Copy the board
 *
 * @param board Board to copy
 */
void Board::copy(const Board &board) {
    // Copy the board
    this->width = board.width;
    this->height = board.height;
    this->percentage = board.percentage;
    this->mines_Total = board.mines_Total;
    this->mines_Left = board.mines_Left;
    this->flags_Total = board.flags_Total;
    this->flags_Left = board.flags_Left;
    this->questions_Total = board.questions_Total;
    this->questions_Left = board.questions_Left;
    this->revealed_Total = board.revealed_Total;
    this->revealed_Left = board.revealed_Left;
    this->hidden_Total = board.hidden_Total;
    this->hidden_Left = board.hidden_Left;
    this->cells_Total = board.cells_Total;
    this->cells_Left = board.cells_Left;
    this->min_mines = board.min_mines;
    this->max_mines = board.max_mines;
    this->status = board.status;
    // Copy the cells
    this->head = copyCells(board.head);
    this->tail = copyCells(board.tail);
    this->current = copyCells(board.current);
}

/**
 * @brief Move the board
 *
 * @param board Board to move
 */
void Board::move(Board &&board) noexcept {
    // Move the board
    this->width = board.width;
    this->height = board.height;
    this->percentage = board.percentage;
    this->mines_Total = board.mines_Total;
    this->mines_Left = board.mines_Left;
    this->flags_Total = board.flags_Total;
    this->flags_Left = board.flags_Left;
    this->questions_Total = board.questions_Total;
    this->questions_Left = board.questions_Left;
    this->revealed_Total = board.revealed_Total;
    this->revealed_Left = board.revealed_Left;
    this->hidden_Total = board.hidden_Total;
    this->hidden_Left = board.hidden_Left;
    this->cells_Total = board.cells_Total;
    this->cells_Left = board.cells_Left;
    this->min_mines = board.min_mines;
    this->max_mines = board.max_mines;
    this->status = board.status;
    // Move the cells
    this->head = std::move(board.head);
    this->tail = std::move(board.tail);
    this->current = std::move(board.current);
}

/**
 * @brief Copy the cells
 *
 * @param CellSPtr Cell to copy
 * @return CellSPtr Pointer to the cell
 */
CellSPtr Board::copyCells(const CellSPtr &cell) {
    // Check if the cell is valid
    if (cell) {
        // Copy the cell
        CellSPtr newCell = std::make_shared<Cell>(*cell);
        // Copy the next cell
        newCell->next = copyCells(cell->next);
        // Return the cell
        return newCell;
    }
    // Return the cell
    return nullptr;
}