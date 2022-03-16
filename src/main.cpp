#include <iostream>
#include <string>
#include "Games/GuessTheNumber.h"
#include "Games/Hangman.h"

void show_the_list_of_commands()
{
    std::cout << R"(
What do you want to do ?
1 : Become clairvoyant
2 : Save a friend
q : I just want to be left alone
    )" << std::endl;
}

static char get_input_from_player()
{
    char choosen_character = '\0';
    std::cin >> choosen_character;
    return static_cast<char>(tolower(choosen_character));
}

int main()
{
    bool quit = false;
    while (!quit) {
        show_the_list_of_commands();
        const auto command = get_input_from_player();
        switch (command) {
        case '1':
            play_guess_the_number();
            break;

        case '2':
            play_hangman();
            break;

        case 'q':
            quit = true;
            break;

        default:
            std::cout << "Sorry don't know this one" << std::endl;
            break;
        }
    }

    // play_guess_the_number();
    // play_hangman();
}