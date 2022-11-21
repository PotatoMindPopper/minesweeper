#include "sleep.h"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#elif __linux__
#include <unistd.h>
#elif __APPLE__
#include <unistd.h>
#else
#include <thread>
#include <chrono>
#endif

/**
 * @brief Sleep for a given number of milliseconds.
 * 
 * @param milliseconds The number of milliseconds to sleep for.
 */
void sleepForTime(const int &milliseconds) {
    #if defined(_WIN32) || defined(_WIN64)
        Sleep(milliseconds);
    #elif __linux__
        usleep(milliseconds * 1000);  // takes microseconds
    #elif __APPLE__
        usleep(milliseconds * 1000);  // takes microseconds
    #else
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    #endif
}
