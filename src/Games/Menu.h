#pragma once

#include "GuessTheNumber.h"
#include "Hangman.h"
#include "NoughtAndCross.h"
#include "PlayerInput.h"


void show_the_list_of_commands()
{
    std::cout << R"(
What do you want to do ?
1 : Become clairvoyant
2 : Save a friend
3 : Make a strategie
q : I just want to be left alone
    )" << std::endl;
}

void show_menu()
{
    bool quit = false;
    while (!quit) {
        show_the_list_of_commands();
        const auto command = get_input_from_the_player<char>();
        switch (command) {
        case '1':
            play_guess_the_number();
            break;

        case '2':
            play_hangman();
            break;

        case '3':
            play_nought_and_cross();
            break;

        case 'q':
            std::cout << "Ok see you another time" << std::endl;
            quit = true;
            break;

        default:
            std::cout << "Sorry don't know this one" << std::endl;
            break;
        }
    }
}