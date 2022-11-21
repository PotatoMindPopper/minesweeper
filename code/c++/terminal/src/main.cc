#include "../include/menu.h"
#include "../include/standard.h"

/**
 * @brief The main function.
 * 
 * Shows an introduction and then the menu for the game.
 * 
 * @return int The exit code.
 */
int main() {
    MenuUPtr menu = std::make_unique<Menu>();
    menu->printIntro();
    menu = nullptr;

    return shutdown();
}

