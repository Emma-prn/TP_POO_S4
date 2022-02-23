#include "Hangman.h"
#include <iostream>
#include <string>
#include <vector>
#include "Random.h"

static std::string pick_a_word_to_guess()
{
    std::vector<std::string> words = {
        "anime",
        "manga",
        "jeux",
        "console",
        "code",
    };
    int element_number = pick_a_random_number(0, static_cast<int>(words.size() - 1));
    return words[element_number];
}

static char get_character_from_player()
{
    char choosen_character = '\0';
    std::cout << "Pick a letter : ";
    std::cin >> choosen_character;
    return static_cast<char>(tolower(choosen_character));
}

static void show_number_of_lives(int number_of_lives)
{
    std::cout << "You've got " << std::to_string(number_of_lives) << " lives." << std::endl;
}

static bool player_is_alive(int number_of_lives)
{
    return (number_of_lives > 0);
}

static bool player_has_won()
{
    return true;
}

void play_hangman()
{
    for (size_t i = 0; i < 10; i++) {
        // std::cout << pick_a_word_to_guess() << std::endl;
        std::cout << get_character_from_player() << std::endl;
    }
}