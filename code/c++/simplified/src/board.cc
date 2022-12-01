#include "board.h"
#include "standard.h"
#include <iostream>

/**
 * @brief Construct a new Board:: Board object.
 */
Board::Board()
    : width(DEFAULT_WIDTH), height(DEFAULT_HEIGHT),
      percentage(DEFAULT_PERCENTAGE) {
    this->initialize();
}

/**
 * @brief Construct a new Board:: Board object.
 *
 * @param width The width of the board.
 * @param height The height of the board.
 * @param percentage The percentage of the mines.
 */
Board::Board(const int &width, const int &height, const int &percentage)
    : width(width), height(height), percentage(percentage) {
    this->initialize();
}

/**
 * @brief Construct a new Board:: Board object.
 *
 * @param BoardUPtr The board to copy.
 */
Board::Board(const BoardUPtr &board) { this->copy(board); }

/**
 * @brief Construct a new Board:: Board object.
 *
 * @param BoardSPtr The board to copy.
 */
Board::Board(const BoardSPtr &board) { this->copy(board); }

/**
 * @brief Destroy the Board:: Board object.
 */
Board::~Board() {
    this->head = nullptr;
    this->tail = nullptr;
    this->current = nullptr;
}

/**
 * @brief Assignment operator.
 *
 * @tparam T Either BoardUPtr or BoardSPtr.
 * @tparam U Either BoardUPtr or BoardSPtr.
 * @param board The board to copy.
 * @return T The copied board.
 */
template <typename T, typename U>
T Board::operator=(const U &board) {
    // Check the type of T and store a string of the type
    std::string type = typeid(T).name();
    // Check the type of U and store a string of the type
    std::string type2 = typeid(U).name();

    // Check if the type of T is a shared pointer of Board
    if (type == "BoardSPtr") {
        // Create a shared pointer of Board, to be returned
        BoardSPtr boardSPtr = std::make_shared<Board>();

        // Check if the type of U is a shared pointer of Board
        if (type2 == "BoardSPtr") {
            // Create a shared pointer of Board, to be copied
            BoardSPtr boardSPtr2 = std::dynamic_pointer_cast<Board>(board);

            // Copy the board and store it in the shared pointer
            boardSPtr->copy(boardSPtr2);

            // Return the copied board
            return boardSPtr;
        }

        // Check if the type of U is a unique pointer of Board
        else if (type2 == "BoardUPtr") {
            // Create a unique pointer of Board, to be copied
            BoardUPtr boardUPtr = std::dynamic_pointer_cast<Board>(board);

            // Copy the board and store it in the shared pointer
            boardSPtr->copy(boardUPtr);

            // Return the copied board
            return boardSPtr;
        }

        // Return the copied board
        else {
            return boardSPtr;
            // or throw an exception
            throw std::invalid_argument("Invalid type");
        }

    } else if (type == "BoardUPtr") {
        // Create a unique pointer of Board, to be returned
        BoardUPtr boardUPtr = std::make_unique<Board>();

        // Check if the type of U is a shared pointer of Board
        if (type2 == "BoardSPtr") {
            // Create a shared pointer of Board, to be copied
            BoardSPtr boardSPtr = std::dynamic_pointer_cast<Board>(board);

            // Copy the board and store it in the unique pointer
            boardUPtr->copy(boardSPtr);

            // Return the copied board
            return boardUPtr;
        }

        // Check if the type of U is a unique pointer of Board
        else if (type2 == "BoardUPtr") {
            // Create a unique pointer of Board, to be copied
            BoardUPtr boardUPtr2 = std::dynamic_pointer_cast<Board>(board);

            // Copy the board and store it in the unique pointer
            boardUPtr->copy(boardUPtr2);

            // Return the copied board
            return boardUPtr;
        }

        // Return the copied board
        else {
            return boardUPtr;
            // or throw an exception
            throw std::invalid_argument("Invalid argument");
        }
    } else {
        // Return a nullptr
        return nullptr;
        // or throw an exception
        throw std::invalid_argument("Invalid argument");
    }
}

/**
 * @brief Copy the board.
 *
 * @param BoardSPtr The board to copy.
 */
void Board::copy(const BoardSPtr &board) {
    if (!board) {
        return;
    }
    this->width = board->width;
    this->height = board->height;
    this->percentage = board->percentage;
    this->total = board->total;
    this->left = board->left;
    this->min_mines = board->min_mines;
    this->max_mines = board->max_mines;
    this->copyCells(board->head, board->tail, board->current);
    this->status = board->status;
}

/**
 * @brief Copy the board.
 *
 * @param BoardUPtr The board to copy.
 */
void Board::copy(const BoardUPtr &board) {
    if (!board) {
        return;
    }
    this->width = board->width;
    this->height = board->height;
    this->percentage = board->percentage;
    this->total = board->total;
    this->left = board->left;
    this->min_mines = board->min_mines;
    this->max_mines = board->max_mines;
    this->copyCells(board->head, board->tail, board->current);
    this->status = board->status;
}

/**
 * @brief Deep copy of the board.
 *
 * @param BoardSPtr The board to copy.
 * @return BoardSPtr The copied board.
 */
BoardSPtr Board::deepCopy(const BoardSPtr &board) const {
    BoardSPtr newBoard = std::make_shared<Board>();
    newBoard->width = board->width;
    newBoard->height = board->height;
    newBoard->percentage = board->percentage;
    newBoard->total = board->total;
    newBoard->left = board->left;
    newBoard->min_mines = board->min_mines;
    newBoard->max_mines = board->max_mines;
    newBoard->copyCells(board->head, board->tail, board->current);
    newBoard->status = board->status;
    return newBoard;
}

/**
 * @brief Shallow copy of the board.
 *
 * @param BoardUPtr The board to copy.
 * @return BoardUPtr The copied board.
 */
BoardUPtr Board::shallowCopy(const BoardUPtr &board) const {
    BoardUPtr newBoard = std::make_unique<Board>();
    newBoard->width = board->width;
    newBoard->height = board->height;
    newBoard->percentage = board->percentage;
    newBoard->total = board->total;
    newBoard->left = board->left;
    newBoard->min_mines = board->min_mines;
    newBoard->max_mines = board->max_mines;
    newBoard->copyCells(board->head, board->tail, board->current);
    newBoard->status = board->status;
    return newBoard;
}

// TODO: Implement these functions correctly

/**
 * @brief Copy the cells.
 *
 * @param CellSPtr The head of the cells to copy.
 * @param CellSPtr The tail of the cells to copy.
 * @param CellSPtr The current cell of the cells to copy.
 */
void Board::copyCells(const CellSPtr &head, const CellSPtr &tail,
                      const CellSPtr &current) {
    // Create a new head and tail
    CellSPtr newHead = std::make_shared<Cell>();
    CellSPtr newTail = std::make_shared<Cell>();

    // Create a new current cell
    CellSPtr newCurrent = std::make_shared<Cell>();

    // Create a new cell
    CellSPtr newCell = std::make_shared<Cell>();

    // Walk through the cells to copy
    for (CellSPtr cell = head; cell != nullptr; cell = cell->next) {
        // Check if the cell is the head
        if (cell == head) {
            // Copy the cell
            newCell = newCell->copy(cell);

            // Set the new head
            newHead = newCell;

            // Set the new current cell
            newCurrent = newCell;
        }

        // Check if the cell is the tail
        else if (cell == tail) {
            // Copy the cell
            newCell = newCell->copy(cell);

            // Set the new tail
            newTail = newCell;

            // Set the new current cell
            newCurrent = newCell;
        }

        // Check if the cell is the current cell
        else if (cell == current) {
            // Copy the cell
            newCell = newCell->copy(cell);

            // Set the new current cell
            newCurrent = newCell;
        }

        // Check if the cell is not the head, tail or current cell
        else {
            // Copy the cell
            newCell = newCell->copy(cell);
        }

        // Check if the cell is not the tail
        if (cell != tail) {
            // Create a new cell
            newCell = std::make_shared<Cell>();

            // Set the next cell
            newCurrent->next = newCell;

            // Set the previous cell
            newCell->previous = newCurrent;

            // Set the new current cell
            newCurrent = newCell;
        }
    }

    // Set the head and tail
    this->head = newHead;
    this->tail = newTail;

    // Set the current cell
    this->current = newCurrent;

    // Set the current cell to the head
    // this->current = this->head;
}

/**
 * @brief Copy the cell.
 *
 * @param CellSPtr The cell to copy.
 * @return CellSPtr The copied cell.
 */
CellSPtr Board::copyCells(const CellSPtr &cell) {
    // Create a new cell
    CellSPtr newCell = std::make_shared<Cell>();

    // Copy the cell
    newCell->x = cell->x;
    newCell->y = cell->y;
    newCell->value = cell->value;
    newCell->state = cell->state;
    newCell->type = cell->type;
    newCell->next = this->copyCells(cell->next);
    newCell->previous = this->copyCells(cell->previous);
    for (int i = 0; i < 8; i++) {
        newCell->neighbours[i] = this->copyCells(cell->neighbours[i]);
    }

    // Return the copied cell
    return newCell;
}

//-----------------------

/**
 * @brief Reveal a cell.
 */
void Board::reveal() {
    // Ask the user what cell to reveal
    int x = 0;
    int y = 0;

    std::cout << "Enter the x coordinate (1 - " << this->width << "): ";
    std::cin >> x;
    // Check if the x coordinate is valid
    while (x < 1 || x > this->width) {
        std::cout << "Invalid x coordinate!" << std::endl;
        std::cout << "Enter the x coordinate (1 - " << this->width << "): ";
        std::cin >> x;
    }

    std::cout << "Enter the y coordinate (1 - " << this->height << "): ";
    std::cin >> y;
    // Check if the y coordinate is valid
    while (y < 1 || y > this->height) {
        std::cout << "Invalid y coordinate!" << std::endl;
        std::cout << "Enter the y coordinate (1 - " << this->height << "): ";
        std::cin >> y;
    }

    // Setback the x and y coordinates, because the user starts counting from 1
    x--;
    y--;

    // TODO: Check if efficiency can be improved, by using the x and y
    // coordinates to find the cell (maybe start from tail or head depending on
    // the coordinates)
    // Set the current cell
    this->current = this->head;
    // Walk through the cells
    for (int i = 0; i < (this->height - 1) * (this->width - 1); i++) {
        // Check if the cell is the one to reveal
        if (this->current->x == x && this->current->y == y) {
            // Reveal the cell
            this->current->reveal();
            break;
        }

        // Set the current cell to the next cell
        this->current = this->current->next;
    }

    // Check if neighbours can be revealed
    this->revealNeighbours(x, y);

    // Check if the cell is a mine
    if (this->current->type == Cell::Type::MINE) {
        // Set the status to lost
        this->status = Status::LOST;
    }
}

/**
 * @brief Reveal the neighbours of a cell.
 *
 * @param int The x coordinate of the cell.
 * @param int The y coordinate of the cell.
 */
void Board::revealNeighbours(const int &x, const int &y) {
    // Set current cell to (x, y)
    this->current = this->head;
    // Walk through the cells
    for (int i = 0; i < (this->height - 1) * (this->width - 1); i++) {
        // Check if the cell is the one to reveal
        if (this->current->x == x && this->current->y == y) {
            break;
        }

        // Set the current cell to the next cell
        this->current = this->current->next;
    }

    // Check if the cell has neighbours that have value 0 or 1
    for (int i = 0; i < 8; i++) {
        // Check if the neighbour is not a nullptr
        if (this->current->neighbours[i] != nullptr) {
            // Check if the neighbour has value 0 or 1
            if (this->current->neighbours[i]->value == 0 ||
                this->current->neighbours[i]->value == 1) {
                // Reveal the neighbour
                this->current->neighbours[i]->reveal();

                // Check if the neighbour of the neighbour has value 0
                if (this->current->neighbours[i]->value == 0) {
                    // Reveal the neighbours of the neighbour
                    this->revealNeighbours(this->current->neighbours[i]->x,
                                           this->current->neighbours[i]->y);
                }
            }
        }
    }
}

/**
 * @brief Reveal all the cells.
 */
void Board::revealAll() {
    // Set the current cell to the head
    this->current = this->head;
    // Walk through the cells
    for (int i = 0; i < (this->height - 1) * (this->width - 1); i++) {
        // Reveal the cell
        this->current->reveal();

        // Set the current cell to the next cell
        this->current = this->current->next;
    }
}

/**
 * @brief reveal the neighbours of current cell.
 */
void Board::revealNeighboursCurrent() {
    // Get x and y coordinates
    int x = this->current->x;
    int y = this->current->y;

    // Reveal the neighbours at (x,y) coordinates
    this->revealNeighbours(x, y);
}

/**
 * @brief Set width
 *
 * @param int The new width
 */
void Board::setWidth(const int &width) {
    // Check if the new width is valid
    if (width < 0 || width > MAX_WIDTH) {
        throw std::invalid_argument("Invalid argument");
    } else {
        this->width = width;
    }
}

/**
 * @brief Set height
 *
 * @param int The new height
 */
void Board::setHeight(const int &height) {
    if (height < 0 || height > MAX_HEIGHT) {
        throw std::invalid_argument("Invalid argument");
    } else {
        this->height = height;
    }
}

/**
 * @brief Set percentage
 *
 * @param float The new percentage
 */
void Board::setPerc(const float &perc) {
    if (perc < 0 || perc > MAX_PERCENTAGE) {
        throw std::invalid_argument("Invalid argument");
    } else {
        // Check if the percentage is within the allowed range, based on the
        // board
        if (this->checkPerc(perc)) {
            this->percentage = perc;
        } else {
            throw std::invalid_argument("Invalid argument");
        }
    }
}
