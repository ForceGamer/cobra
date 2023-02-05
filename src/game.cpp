//
// Created by force on 2/2/23.
//

#include <random>
#include <chrono>
#include <string> //Apparently <string> is needed specifically for Windows to compile

#include "game.h"
#include "colors.h"

void numRepeat() {
    const int MAX_DISPLAY = 9; //The number that is displayed. Keep in single digit.
    const int MAX_COUNT = 7;
    const int MIN_COUNT = 1;

    std::random_device rd;
    std::mt19937 mt(rd());

    std::uniform_int_distribution<int>
            displayRand(MIN_COUNT, MAX_DISPLAY);
    std::uniform_int_distribution<int>
            countRand(1, MAX_COUNT);

    int display;
    int count;

    //let now = Instant::now();
    int fails = 0;
    int successes = 0;
    bool stop = false;

    std::string input;
    int parsedInput;

    std::chrono::steady_clock::time_point
            before = std::chrono::steady_clock::now();

    while(true) {
            display = displayRand(mt);
            count = countRand(mt);
#ifdef IS_DEBUG
            std::cout << "Display: " << display << std::endl;
            std::cout << "Count: " << count << std::endl;
#endif

            // This loop allows the user to correct potential mistakes
            // by reusing the same generated numbers until they get it right
            while(true) {
                for(int i=1; i<=count; i++) {
                        std::cout << display;
                }
                std::cout << std::endl;

                std::cout << "Answer:";
                std::cin >> input;
                // Check for Stop
                if (input == "s") {
                    stop = true;
                    break;
                } else {
                    try { parsedInput = std::stoi(input); }
                    catch (const std::invalid_argument &) {
                        continue;
                    }

                    // Correct
                    if (parsedInput == count) {
                        successes += 1;
                        std::cout << GREEN << "Correct" << ENDCOLOR << std::endl;
                        break;
                    // Incorrect
                    } else {
                        fails += 1;
                        std::cout << RED << "Incorrect" << ENDCOLOR << std::endl;
                    }
                }
                if ((successes + fails) >= (20 - 1)) {
                    stop = true;
                }
            }
            //failed_attempts = 0;
            if (stop) {break;} else {
                std::cout << "The count was " << count << std::endl;
            }
    }
    std::chrono::steady_clock::time_point
            after = std::chrono::steady_clock::now();
    long elapsed = std::chrono::duration_cast<std::chrono::seconds>(after - before).count();

    std::cout << "Time elapsed: " << elapsed << "s" << std::endl;
    if (fails != 0) {
        std::cout << GREEN << "You answered correct " << successes << " times" << ENDCOLOR << std::endl;
        std::cout << RED << "You answered wrong " << fails << " times" << ENDCOLOR << std::endl;
    } else {
        std::cout << GREEN << "You answered everything correctly!!" << ENDCOLOR << std::endl;
    }
    std::cout << "Score: " << ((successes - fails) * 10 / elapsed) << std::endl;
}
