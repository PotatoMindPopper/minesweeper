#ifndef __STANDARD_H__
#define __STANDARD_H__

#include <vector>

char processChoice(std::vector<char> &choices);
void processChoice(std::vector<char> &choices, char &choice);

void clearScreen();
void pressEnter();
void loadingDots();
void loadingDots(const int &n);

int shutdown();


#endif // __STANDARD_H__