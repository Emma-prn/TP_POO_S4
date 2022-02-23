#include "GuessTheNumber.h"
#include <iostream>
#include <string>
#include "Random.h"


static int get_number_from_player()
{
    int choosen_number = -1;
    while ((std::cout << "Please choose a number between 0 and 100 : ") && (!(std::cin >> choosen_number) || choosen_number < 0 || choosen_number > 100)) {
        std::cout << "That's not a number between 0 and 100. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return choosen_number;
}

void play_guess_the_number()
{
    std::cout << "================ Guess the number =================" << std::endl;
    int maximum       = 100;
    int minimum       = 0;
    int player_try    = 0;
    int random_number = pick_a_random_number(minimum, maximum);
    std::cout << "I picked a number between 0 and 100." << std::endl;
    bool guessed = false;
    while (!guessed) {
        int player_number = get_number_from_player();
        if (player_number < random_number) {
            std::cout << "It's greater" << std::endl;
        }
        else if (player_number > random_number) {
            std::cout << "It's smaller" << std::endl;
        }
        else {
            guessed = true;
        }
        player_try++;
    }
    std::cout << "Congrats, you won ! It take you " << std::to_string(player_try) << " try." << std::endl;
}