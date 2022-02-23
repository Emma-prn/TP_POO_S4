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

void play_hangman()
{
    for (size_t i = 0; i < 10; i++) {
        std::cout << pick_a_word_to_guess() << std::endl;
    }
}