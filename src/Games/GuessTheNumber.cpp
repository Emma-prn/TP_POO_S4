#include "GuessTheNumber.h"
#include <iostream>
#include <string>
#include "PlayerInput.h"
#include "Random.h"

static int get_number_from_player(const int& minimum, const int& maximum)
{
    int number_choosen = -1;
    while ((std::cout << "Please choose a number between " << std::to_string(minimum) << " and " << std::to_string(maximum) << " : ") && (!(std::cin >> number_choosen) || number_choosen < 0 || number_choosen > 100)) {
        number_choosen = get_input_from_the_player<int>();
    }
    return number_choosen;
}

void play_guess_the_number()
{
    std::cout << "================ Guess the number =================" << std::endl;
    int maximum       = 100;
    int minimum       = 0;
    int player_try    = 0;
    int random_number = pick_a_random_number(minimum, maximum);
    std::cout << "I picked a number between " << std::to_string(minimum) << " and " << std::to_string(maximum) << std::endl;
    bool guessed = false;
    while (!guessed) {
        int player_number = get_number_from_player(minimum, maximum);
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