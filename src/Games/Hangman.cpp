#include "Hangman.h"
#include <assert.h>
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
    assert(word.size() == letters_guessed.size());
    std::string word_guessed = std::string(word.size(), '_');
    for (size_t i = 0; i < word.size(); i++) {
        if (letters_guessed[i]) {
            word_guessed[i] = word[i];
        }
    }
    std::cout << word_guessed << std::endl;
}

static bool word_contains(char letter, std::string_view word)
{
    return true;
}

static void remove_one_life(int& lives_count)
{
    lives_count--;
}

static void show_congrats_message(const std::string& word_to_guess)
{
    std::cout << "Congrats, you save a life !" << std::endl;
    std::cout << "The word was " << word_to_guess << std::endl;
}

static void show_defeat_message(const std::string& word_to_guess)
{
    std::cout << "... Well, he died." << std::endl;
    std::cout << "The word was " << word_to_guess << std::endl;
}

void play_hangman()
{
    std::cout << "================ Hangman =================" << std::endl;
    int         number_of_lives = -10;
    std::string choosen_word    = pick_a_word_to_guess();
    show_number_of_lives(number_of_lives);
    show_word_to_guess_with_missing_letters("console", {true, false, true, true, false, false, true});
    show_congrats_message(choosen_word);
    show_defeat_message(choosen_word);
}