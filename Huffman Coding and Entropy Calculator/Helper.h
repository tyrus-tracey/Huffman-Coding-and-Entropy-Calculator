/*
    General helper functions not tied to a specific class.
*/

#pragma once
#include <iostream>
#include <sstream>
#include <string>
enum letters { A = 0, B = 1, C = 2, D = 3, E = 4 };
template <typename T>

// Set array values to 0
void initializeArray(T* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
    return;
}

// Parse string into chars and record frequencies
void readInputDistribution(std::string input, int* distribution) {
    char temp;
    std::stringstream inputstream(input);
    while (inputstream >> temp) {
        switch (temp) {
        case 'A':
            distribution[A]++;
            break;
        case 'B':
            distribution[B]++;
            break;
        case 'C':
            distribution[C]++;
            break;
        case 'D':
            distribution[D]++;
            break;
        case 'E':
            distribution[E]++;
            break;
        default:
            break;
        }
    }
    return;
}

// Print char frequencies
void displayDistribution(int* distribution) {
    std::cout << "A: " << distribution[A] << std::endl;
    std::cout << "B: " << distribution[B] << std::endl;
    std::cout << "C: " << distribution[C] << std::endl;
    std::cout << "D: " << distribution[D] << std::endl;
    std::cout << "E: " << distribution[E] << std::endl;
    return;
}
