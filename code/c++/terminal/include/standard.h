#ifndef __STANDARD_H__
#define __STANDARD_H__

#include <vector>

int shutdown();
int randomN(const int &min, const int &max);
int randomNTime(const int &min, const int &max);

void clearScreen();
void pressEnter();
void loadingDots();
void loadingDots(const int &n);
void processChoice(std::vector<char> &choices, char &choice);

char randomNumber();
char randomUpperLetter();
char randomLowerLetter();
char* randomString(const int &n);
char processChoice(std::vector<char> &choices);

#endif // __STANDARD_H__