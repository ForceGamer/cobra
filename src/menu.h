//
// Created by force on 2/2/23.
//

#ifndef COBRA_MENU_H
#define COBRA_MENU_H

#include <iostream>
#include <vector>

class Menus {

public:
    void parseAction(const std::string &action);

    void openMenu(const std::string &menuID);

private:
    struct Menu {
        //std::string id;
        std::string title;
        bool multi;
        std::vector<std::string> choices;
    };

    // Menus:
    Menu mainMenu{
        //"main",
        "Welcome to Cobra",
        false,
        {"Repeat Game"},
    };
};
#endif //COBRA_MENU_H
