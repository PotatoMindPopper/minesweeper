#include "../include/menu.h"
#include "../include/constants.h"
#include "../include/table.h"
#include <iostream>

/**
 * @brief The main function.
 * 
 * Shows an introduction and then the menu for the game.
 * 
 * @return int The exit code.
 */
int main() {
    TableSPtr table = std::make_shared<Table>();

    printIntro();
    table->menu();

    return shutdown();
}

