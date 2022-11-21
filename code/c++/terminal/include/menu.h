#ifndef __MENU_H__
#define __MENU_H__

#include "standard.h"
#include "table.h"
#include <iostream>
#include <stack>

typedef std::unique_ptr<class Menu> MenuUPtr;

struct Choices {
    enum Type {
        Undefined,
        Intro,
        Start,
        Options,
        End,
        Wrong
    } type{Undefined};
    std::string str{""};
    char choice{'\0'};
};

class Menu {
    public:
        Menu();
        ~Menu();

        void printIntro();

    private:
        Choices choices{Choices::Type::Undefined, "", '\0'};
        TableSPtr currentTable{nullptr};
        std::stack<TableSPtr> tables{};

        void printMainMenu();
        void processMainMenu();
        void processMainChoice();
        void getChoice();
        void wrongChoice();
        void resetChoices();

        char debugMenu();

};

#endif // __MENU_H__