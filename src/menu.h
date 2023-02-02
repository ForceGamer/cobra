//
// Created by force on 2/2/23.
//

#ifndef COBRA_MENU_H
#define COBRA_MENU_H

#include <iostream>
#include <vector>

class menu {
    struct Menu {
        std::string title;
        bool multi;
        std::vector<std::string> choices;
    };

    void openMenu(const Menu& menu);

    void parseAction(const std::string& action);
};


#endif //COBRA_MENU_H
