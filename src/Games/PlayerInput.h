#pragma once
#include <iostream>

template<typename T>
T get_input_from_the_player()
{
    T input;
    while (!(std::cin >> input)) {
        std::cin.clear();
        std::cout << "Invalide input" << std::endl;
    }
    return static_cast<char>(tolower(input));
}

template<>
int get_input_from_the_player<int>()
{
    int input;
    while ((std::cout << "Please choose a number between 0 and 100 : ") && (!(std::cin >> input) || input < 0 || input > 100)) {
        std::cout << "That's not a number between 0 and 100. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return input;
}