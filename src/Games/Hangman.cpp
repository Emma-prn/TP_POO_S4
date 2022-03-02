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

static bool player_has_won(const std::vector<bool>& letters_guessed)
{
    return std::all_of(letters_guessed.begin(), letters_guessed.end(), [](bool letter_guessed) {
        return letter_guessed;
    });
}

static void show_word_to_guess_with_missing_letters(const std::string& word, const std::vector<bool>& letters_guessed)
{
    std::string underscore = std::string(word.size(), '_');
    std::cout << underscore << std::endl;
}

void play_hangman()
{
    std::cout << "================ Hangman =================" << std::endl;
    int number_of_lives = -10;
    show_number_of_lives(number_of_lives);
    if (player_is_alive(number_of_lives)) {
        std::cout << "Still alive" << std::endl;
    }
    else {
        std::cout << "Not anymore" << std::endl;
    }
}