#ifndef __CONSTANTS_HPP__
#define __CONSTANTS_HPP__

/* Define the boundaries of the board and the game state
*/
const int MAX_WIDTH{30};            // Maximum width of the board
const int MAX_HEIGHT{30};           // Maximum height of the board
const int MIN_WIDTH{4};             // Minimum width of the board
const int MIN_HEIGHT{4};            // Minimum height of the board
const int MAX_PERCENTAGE{99};       // Maximum percentage of the mines
const int MIN_PERCENTAGE{1};        // Minimum percentage of the mines
const int MIN_TIME{0};              // Minimum time

/* Define the default values of the board
*/
const int DEFAULT_WIDTH{10};        // Default width of the board
const int DEFAULT_HEIGHT{10};       // Default height of the board
const int DEFAULT_PERCENTAGE{30};   // Default percentage of the mines

/* Define the default values of un-initialized or unused variables
*/
const int UNDEFINED_INT{-1};        // Undefined integer
const char UNDEFINED_CHAR{'\0'};    // Undefined character

/* Define the characters used to represent the board
*/
const char MINE{'*'};               // Mine
const char FLAG{'F'};               // Flag
const char QUESTION{'?'};           // Question mark
const char EMPTY{' '};              // Empty cell
const char HIDDEN{'#'};             // Hidden cell

/* Define the keys used to handle the menu items
*/
const char UP_KEY{'w'};             // Up
const char UP_KEY_1{'i'};           // Up
const char DOWN_KEY{'s'};           // Down
const char DOWN_KEY_1{'k'};         // Down
const char LEFT_KEY{'a'};           // Left
const char LEFT_KEY_1{'j'};         // Left
const char RIGHT_KEY{'d'};          // Right
const char RIGHT_KEY_1{'l'};        // Right
const char FLAG_KEY{'f'};           // Flag
const char QUIT_KEY{'q'};           // Quit
const char QUESTION_KEY{'e'};       // Question mark
const char REVEAL_KEY{'r'};         // Reveal

/* Define the coordinates of the neighbors of a cell on the board
*/
const int UP{0};                    // Up
const int UP_RIGHT{1};              // Up right
const int RIGHT{2};                 // Right
const int DOWN_RIGHT{3};            // Down right
const int DOWN{4};                  // Down
const int DOWN_LEFT{5};             // Down left
const int LEFT{6};                  // Left
const int UP_LEFT{7};               // Up left

/* Define the number of neighbors of a cell on the board
*/
const int NEIGHBORS{8};             // Number of neighbors

#endif // __CONSTANTS_H__