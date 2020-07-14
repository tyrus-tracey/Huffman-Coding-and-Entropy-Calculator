/*
    General helper functions not tied to a specific class.
*/

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include "Node.h"
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
std::vector<Node> readInputDistribution(std::string input) {
    char temp;
    std::vector<Node> distribution = { Node("A",0), Node("B",0), Node("C",0), Node("D",0), Node("E",0) };
    std::vector<Node>::iterator iter = distribution.begin();

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

std::vector<Node>::iterator findMin(std::vector<Node>& vec) {
    std::vector<Node>::iterator min = vec.begin();
    std::vector<Node>::iterator iter = vec.begin();
    while (iter != vec.end()) {
        if ((*iter).getFrequency() < (*min).getFrequency()) {
            min = iter;
        }
        iter++;
    }
    return min;
}

// Print char frequencies
void displayDistribution(std::vector<Node> distribution) {
    std::cout << "A: " << distribution[A].getFrequency() << std::endl;
    std::cout << "B: " << distribution[B].getFrequency() << std::endl;
    std::cout << "C: " << distribution[C].getFrequency() << std::endl;
    std::cout << "D: " << distribution[D].getFrequency() << std::endl;
    std::cout << "E: " << distribution[E].getFrequency() << std::endl;
    return;
}
