//
// Created by force on 2/2/23.
//

#include "menu.h"
#include "colors.h"
#include "game.h"

void Menus::openMenu(const std::string &menuID) {
    Menu menu = mainMenu;
    /*if (menuID == "sample") {
        menu = sampleMenu;
    }*/

    std::string input;
    int parsedInput;
    while(true) {
            //Title
            std::cout << BLUE << menu.title << ENDCOLOR << std::endl;

            //Menu
            for (int i=0; i<menu.choices.size(); i++) {
                std::cout << (i+1) << " " << menu.choices.at(i) << std::endl;
            }
            std::cout << "Type 'q' to Quit" << std::endl;
            std::cout << "Select:";
            std::cin >> input;

            // Break if user asks to Quit
            if (input == "q") {break;}

            parsedInput = std::stoi(input);
            switch (parsedInput) {
                    case 1: {
                        numRepeat();
                        break;
                    } //TODO: Change to use dynamic data
                    case 2: {
                        //Other thing
                    }
                    default: {
                        std::cout << RED << "Invalid selection" << ENDCOLOR << std::endl;
                        break;
                    }
            }
    }
}

void Menus::parseAction(const std::string &action) {

}