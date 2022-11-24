#include "../include/table.h"
#include <cmath>
#include <iostream>

/**
 * @brief Construct a new Table:: Table object
 * 
 */
Table::Table() {
    // Do nothing
}

/**
 * @brief Destroy the Table:: Table object
 * 
 */
Table::~Table() {
    table = UNDEFINED_PTR;
}

/**
 * @brief Get the user input for the height of the table
 * 
 * @return int The height of the table
 */
int Table::getHeight() {
    std::cout << "Enter the height of the table: ";
    int height;
    std::cin >> height;
    if (height < MIN_HEIGHT) {
        std::cout << "Height must be at least " << MIN_HEIGHT << std::endl;
        return getHeight();
    } else if (height > MAX_HEIGHT) {
        std::cout << "Height must be at most " << MAX_HEIGHT << std::endl;
        return getHeight();
    } else {
        return height;
    }
}

/**
 * @brief Get the user input for the width of the table
 * 
 * @return int The width of the table
 */
int Table::getWidth() {
    std::cout << "Enter the width of the table: ";
    int width;
    std::cin >> width;
    while (true) {
        if (width > MAX_WIDTH) {
            std::cout << "Invalid width: " << width << std::endl;
            std::cout << "Width must be less then " << MAX_WIDTH << std::endl;
        } else if (width < MIN_WIDTH) {
            std::cout << "Invalid width: " << width << std::endl;
            std::cout << "Width must be greater than " << MIN_WIDTH << std::endl;
        } else {
            std::cout << "Width is set to " << width << std::endl;
            return width;
        }
        std::cout << "Enter a new width: ";
        std::cin >> width;
    }
}

/**
 * @brief Make a shallow copy of the table handler, all pointers are copied.
 * 
 * @return TableUPtr 
 */
TableUPtr Table::shallowCopy() const {
    TableUPtr copy = std::make_unique<Table>();
    copy->gameSetup = this->gameSetup;
    copy->gameStarted = this->gameStarted;
    copy->gameEnded = this->gameEnded;
    copy->gameWon = this->gameWon;
    copy->showCell = this->showCell;
    copy->markMine = this->markMine;
    copy->showNeighbors = this->showNeighbors;
    copy->openNeighbors = this->openNeighbors;
    copy->height = this->height;
    copy->width = this->width;
    copy->min_mines = this->min_mines;
    copy->max_mines = this->max_mines;
    copy->totalMines = this->totalMines;
    copy->flags = this->flags;
    copy->opened = this->opened;
    copy->highscore = this->highscore;
    copy->time = this->time;
    copy->percentage = this->percentage;
    copy->totalMines = this->totalMines;
    copy->totalFlags = this->totalFlags;
    copy->table = this->copyTable();
    return copy;
}

/**
 * @brief Make a deep copy of the table handler.
 * 
 * @return TableSPtr 
 */
TableSPtr Table::deepCopy() const {
    TableSPtr copy = std::make_shared<Table>();
    copy->gameSetup = this->gameSetup;
    copy->gameStarted = this->gameStarted;
    copy->gameEnded = this->gameEnded;
    copy->gameWon = this->gameWon;
    copy->showCell = this->showCell;
    copy->markMine = this->markMine;
    copy->showNeighbors = this->showNeighbors;
    copy->openNeighbors = this->openNeighbors;
    copy->height = this->height;
    copy->width = this->width;
    copy->min_mines = this->min_mines;
    copy->max_mines = this->max_mines;
    copy->totalMines = this->totalMines;
    copy->flags = this->flags;
    copy->opened = this->opened;
    copy->highscore = this->highscore;
    copy->time = this->time;
    copy->percentage = this->percentage;
    copy->totalMines = this->totalMines;
    copy->totalFlags = this->totalFlags;
    copy->table = this->copyTable();
    return copy;
}

/**
 * @brief Copy a cell object/pointer.
 * 
 * @param table The pointer to the cell to copy.
 * @return CellSPtr 
 */ 
CellSPtr Table::copyCell(const CellSPtr &cell) const {
    if (!cell)
        return nullptr;

    CellSPtr newCell = std::make_shared<Cell>();

    newCell->mine = cell->mine;
    newCell->flagged = cell->flagged;
    newCell->opened = cell->opened;
    newCell->x = cell->x;
    newCell->y = cell->y;

    newCell->next = this->copyCell(cell->next);
    newCell->prev = this->copyCell(cell->prev);

    for (int i = 0; i < 8; i++)
        newCell->neighbors[i] = this->copyCell(cell->neighbors[i]);

    return newCell;
}

/**
 * @brief Copy the table object/pointer.
 * 
 * @return CellSPtr 
 */ 
CellSPtr Table::copyTable() const { return this->copyCell(this->table); }

/**
 * @brief Get the cell at the given coordinates using while loops.
 * 
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @return CellSPtr 
 */
CellSPtr Table::getCellWhile(const int &x, const int &y) const {
    CellSPtr cell = this->table;
    while (cell) {
        if (cell->x == x && cell->y == y)
            return cell;
        cell = cell->next;
    }
    return nullptr;
}

/**
 * @brief Get the cell at the given coordinates using recursion.
 * 
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @param cell The cell to start from.
 * @return CellSPtr 
 */
CellSPtr Table::getCellRec(const int &x, const int &y, const CellSPtr &cell) const {
    if (cell->x == x && cell->y == y)
        return cell;
    else if (cell->next)
        return this->getCellRec(x, y, cell->next);
    else
        return nullptr;
}

/**
 * @brief Get the cell at the given coordinates using for loops.
 * 
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @return CellSPtr 
 */
CellSPtr Table::getCellFor(const int &x, const int &y) const {
    CellSPtr cell = this->table;
    for (int i = 0; i < x; i++) {
        if (cell->x == x)
            break;
        else if (cell->neighbors[RIGHT])
            cell = cell->neighbors[RIGHT];
        else
            return nullptr;
    }
    for (int i = 0; i < y; i++) {
        if (cell->y == y)
            return cell;
        else if (cell->neighbors[DOWN])
            cell = cell->neighbors[DOWN];
        else
            return nullptr;
    }
    return nullptr;
}

/**
 * @brief Place the mines on the grid.
 * 
 * This will be done using the this->percentage value.
 */
void Table::placeMines() const {
    // Get the number of mines;
    // This is updated every time a new game is started;
    int mines = this->totalMines;

    // Place the mines;
    CellSPtr cell = this->table;
    while (cell) {
        if (mines > 0) {
            if (randomNumber(0, 1) % 2 == 0) {
                cell->mine = true;
                mines--;
            }
        }
        cell = cell->next;
    }

    // Set the numbers;
    cell = this->table;
    while (cell) {
        if (!cell->mine) {
            for (int i = 0; i < 8; i++) {
                if (cell->neighbors[i] && cell->neighbors[i]->mine)
                    cell->neighbors_mines++;
            }
        }
        cell = cell->next;
    }

    // Reset cell;
    cell = nullptr;
}

/**
 * @brief Create the grid out of cells.
 * 
 * Begin by creating the first cell, then create the rest of the cells.
 * First link all cell->next and cell->prev pointers.
 * Then link all cell->neighbors pointers.
 */
void Table::createGrid() {
    // Grid is from 0 - (height - 1) and 0 - (width - 1);
    // This is because we start from 0 and not 1.

    // Rules for the linking of the cells;
    // Next:
        // if x == width, then next = first cell of next row;
        // else next = next cell;
    // Prev:
        // if x == 0, then prev = last cell of previous row;
        // else prev = previous cell;

    // Create the first cell;
    this->table = std::make_shared<Cell>();
    this->table->x = 0;
    this->table->y = 0;
    CellSPtr curr_walker = this->table;
    CellSPtr prev_walker = this->table;

    // Create the rest of the cells;
    for (int h = 0; h < this->height; h++) {
        // All next rows have curr_walker->prev = last cell of previous row;
        // All next rows have prev_walker->next = first cell of next row;
        if (h > 0) {
            prev_walker = curr_walker; // save last cell of previous row;
            curr_walker = std::make_shared<Cell>();
            prev_walker->next = curr_walker;
            curr_walker->prev = prev_walker;
            curr_walker->x = 0;
            curr_walker->y = h;
        }

        // Create the rest of the cells in the row;
        for (int w = 1; w < this->width; w++) {
            prev_walker = curr_walker;
            curr_walker = std::make_shared<Cell>();
            prev_walker->next = curr_walker;
            curr_walker->prev = prev_walker;
            curr_walker->x = w;
            curr_walker->y = h;
        }
    }

    // Link all neighbors;
    this->setNeighbors();

    // Set mines and numbers;
    this->placeMines();

    // Reset the all local cell pointers;
    curr_walker = nullptr;
    prev_walker = nullptr;
}

/**
 * @brief Set the neighbors of all cells.
 * 
 */
void Table::setNeighbors() const {
    CellSPtr cell = this->table;
    while (cell) {
        this->setNeighbors(cell);
        cell = cell->next;
    }
    cell = nullptr;
}

/**
 * @brief Set the neighbors of the given cell.
 * 
 * @param cell The cell to set the neighbors of.
 */
void Table::setNeighbors(const CellSPtr &cell) const {
    // Neighbors:
        // neighbors[UP] = x, y - 1;
        // neighbors[DOWN] = x, y + 1;
        // neighbors[LEFT] = prev;
        // neighbors[RIGHT] = next;
        // neighbors[UP_LEFT] = neighbors[UP]->neighbors[LEFT];
        // neighbors[UP_RIGHT] = neighbors[UP]->neighbors[RIGHT];
        // neighbors[DOWN_LEFT] = neighbors[DOWN]->neighbors[LEFT];
        // neighbors[DOWN_RIGHT] = neighbors[DOWN]->neighbors[RIGHT];
        // if (at the edge of the grid) neighbors[edges] = nullptr;

    // Set neighbors[UP];
    if (cell->y > 0)
        cell->neighbors[UP] = this->getCellFor(cell->x, cell->y - 1);
    else
        cell->neighbors[UP] = nullptr;

    // Set neighbors[DOWN];
    if (cell->y < this->height - 1)
        cell->neighbors[DOWN] = this->getCellFor(cell->x, cell->y + 1);
    else
        cell->neighbors[DOWN] = nullptr;

    // Set neighbors[LEFT];
    if (cell->x > 0)
        cell->neighbors[LEFT] = cell->prev;
    else
        cell->neighbors[LEFT] = nullptr;

    // Set neighbors[RIGHT];
    if (cell->x < this->width - 1)
        cell->neighbors[RIGHT] = cell->next;
    else
        cell->neighbors[RIGHT] = nullptr;

    // Set neighbors[UP_LEFT];
    if (cell->neighbors[UP] && cell->neighbors[LEFT])
        cell->neighbors[UP_LEFT] = cell->neighbors[UP]->neighbors[LEFT];
    else
        cell->neighbors[UP_LEFT] = nullptr;

    // Set neighbors[UP_RIGHT];
    if (cell->neighbors[UP] && cell->neighbors[RIGHT])
        cell->neighbors[UP_RIGHT] = cell->neighbors[UP]->neighbors[RIGHT];
    else
        cell->neighbors[UP_RIGHT] = nullptr;

    // Set neighbors[DOWN_LEFT];
    if (cell->neighbors[DOWN] && cell->neighbors[LEFT])
        cell->neighbors[DOWN_LEFT] = cell->neighbors[DOWN]->neighbors[LEFT];
    else
        cell->neighbors[DOWN_LEFT] = nullptr;

    // Set neighbors[DOWN_RIGHT];
    if (cell->neighbors[DOWN] && cell->neighbors[RIGHT])
        cell->neighbors[DOWN_RIGHT] = cell->neighbors[DOWN]->neighbors[RIGHT];
    else
        cell->neighbors[DOWN_RIGHT] = nullptr;
}

/**
 * @brief Initialize a new game.
 * 
 */
void Table::newGame() {
    // Set grid height;
    this->height = this->getHeight();

    // Set grid width;
    this->width = this->getWidth();

    // Set min and max mines;
    int gridSize = (this->height + 1) * (this->width + 1);
    this->min_mines = (int) round(100.0f * ((float)(gridSize - 10) / gridSize));
    this->max_mines = (int) fmax(1, (int) round(100.0f / gridSize));

    // Set user mines percentage;
    this->percentage = this->getPercentage();

    this->totalMines = (int) round((float)this->percentage * (float)(this->height - 1) * (float)(this->width - 1) / 100.0f);
    this->totalFlags = this->totalMines;
    this->opened = 0;
    this->flags = 0;

    // Create and setup the grid;
    this->createGrid();

    // Time the game;
    this->startTime = std::chrono::system_clock::now();

    // Game is setup;
    this->gameSetup = true;

    std::cout << "New game started!" << std::endl;
    
    // Start the game loop; Jump to menu;
    this->playGame();
}

/**
 * @brief Get the percentage of mines.
 * 
 * @return int The percentage of mines.
 */
int Table::getPercentage() {
    // TODO: Pas deze line nog aan naar min en max values;
    std::cout << "Enter the percentage of mines (1 - 99): ";
    int percentage;
    std::cin >> percentage;
    while (percentage < MIN_PERCENTAGE || percentage > MAX_PERCENTAGE) {
        std::cout << "Invalid percentage. Enter a percentage between 1 and 99: ";
        std::cin >> percentage;
    }




    int iPerc{UNDEFINED_INT};
    std::cout << "Enter the percentage of mines: ";
    std::cin >> iPerc;



    // Check if iPerc is valid, within the grid bounds;

    // If precent_mines is already within the given input and predetermined small value.
    if (!(fabs(this->percentage - iPerc) <= 0.5f)) {
        int gridSize = (this->height + 1) * (this->width + 1);
        int tempMines = (int) round((float) iPerc / 100.0f * gridSize);
        if (tempMines >= this->min_mines && tempMines <= this->max_mines) {
            this->percentage = iPerc;
        } else {
            this->percentage = DEFAULT_PERCENTAGE;
            std::cout << "Invalid percentage of mines. Using default value of " << this->percentage << "%." << std::endl;
        }
    }




    return percentage;
}

/**
 * @brief Play the game.
 * 
 */
void Table::playGame() {
    // Check if the game is setup;
    if (!this->gameSetup) {
        std::cout << "Game is not setup yet!" << std::endl;
        return;
    }

    // Check if the game is over;
    if (this->gameEnded) {
        std::cout << "Game is over!" << std::endl;
        return;
    }

    // Check if the game is won;
    if (this->gameWon) {
        std::cout << "Game is won!" << std::endl;
        return;
    }

    // Print the grid;
    this->printGrid();

    // Get the user input;
    int x, y;
    std::cout << "Enter the x and y coordinates: ";
    std::cin >> x >> y;

    // Check if the user input is valid;
    if (x < 0 || x > this->width - 1 || y < 0 || y > this->height - 1) {
        std::cout << "Invalid coordinates!" << std::endl;
        return;
    }

    // Get the cell;
    CellSPtr cell = this->getCellFor(x, y);

    // Check if the cell is already opened;
    if (cell->opened) {
        std::cout << "Cell is already opened!" << std::endl;
        return;
    }

    // Check if the cell is flagged;
    if (cell->flagged) {
        std::cout << "Cell is flagged!" << std::endl;
        return;
    }

    // Check if the cell is a mine;
    if (cell->mine) {
        // Game over;
        this->gameEnded = true;
        this->gameWon = false;

        // Open all cells;
        this->openAllCells();

        // Print the grid;
        this->printGrid();

        // Print the game over message;
        std::cout << "Game over!" << std::endl;

        // Print the game time;
        this->printGameTime();

        // Jump to menu;
        this->menu();
    } else {
        // Open the cell;
        this->openCell(cell);

        // Check if the game is won;
        if (this->gameWon) {
            // Print the grid;
            this->printGrid();

            // Print the game won message;
            std::cout << "Game won!" << std::endl;

            // Print the game time;
            this->printGameTime();

            // Jump to menu;
            this->menu();
        } else {
            // Jump to playGame;
            this->playGame();
        }
    }
}
