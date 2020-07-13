/*
    General helper functions not tied to a specific class.
*/

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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
std::vector<int> readInputDistribution(std::string input) {
    char temp;
    std::vector<int> distribution(5);
    std::vector<int>::iterator iter = distribution.begin();
    while (iter != distribution.end()) {
        *iter = 0;
        iter++;
    }

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
    return distribution;
}

std::vector<int>::iterator findMin(std::vector<int>& vec) {
    std::vector<int>::iterator min = vec.begin();
    std::vector<int>::iterator iter = vec.begin();
    while (iter != vec.end()) {
        if (*iter < *min) {
            min = iter;
        }
        iter++;
    }
    return min;
}

// Print char frequencies
void displayDistribution(std::vector<int> distribution) {
    std::cout << "A: " << distribution[A] << std::endl;
    std::cout << "B: " << distribution[B] << std::endl;
    std::cout << "C: " << distribution[C] << std::endl;
    std::cout << "D: " << distribution[D] << std::endl;
    std::cout << "E: " << distribution[E] << std::endl;
    return;
}
