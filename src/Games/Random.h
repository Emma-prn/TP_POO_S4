#pragma once
#include <random>

template<typename T>
T pick_a_random_number(const T& minimum, const T& maximum)
{
    std::random_device                 generator;
    std::mt19937                       mt(generator());
    std::uniform_int_distribution<int> distribution(minimum, maximum);
    return distribution(generator);
}