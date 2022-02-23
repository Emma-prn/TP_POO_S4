#pragma once
#include <random>

int pick_a_random_number(int& minimum, int& maximum)
{
    std::random_device                 generator;
    std::mt19937                       mt(generator());
    std::uniform_int_distribution<int> distribution(minimum, maximum);
    return distribution(generator);
}