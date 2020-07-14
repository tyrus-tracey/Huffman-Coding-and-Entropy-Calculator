/*
    General helper functions not tied to a specific class.
*/

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Node.h"
#include "Helper.h"
#include <math.h>

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

std::vector<Node>::iterator findMin(std::vector<Node>& distribution) {
    std::vector<Node>::iterator min = distribution.begin();
    std::vector<Node>::iterator iter = distribution.begin();
    while (iter != distribution.end()) {
        if ((*iter).getFrequency() < (*min).getFrequency()) {
            min = iter;
        }
        iter++;
    }
    return min;
}

int getSum(std::vector<Node> distribution)
{
    std::vector<Node>::iterator iter = distribution.begin();
    int sum = 0;
    while (iter != distribution.end()) {
        sum += (*iter).getFrequency();
        iter++;
    }
    return sum;
}

//DOUBLE CHECK CALCULATIONS
void calculateFirstEntropy(std::vector<Node> distribution)
{
    int sum = getSum(distribution);
    double entropy = 0.0;
    std::vector<Node>::iterator iter = distribution.begin();
    while (iter != distribution.end()) {
        double prob = double((*iter).getFrequency()) / double(sum);
        if (prob != 0) {
            entropy -= prob * log2(prob);
        }
        iter++;
    }
    std::cout << "First-Order Entropy: " << entropy << std::endl;
}

// Print char frequencies
void displayDistribution(std::vector<Node> distribution) {
    std::cout << "A: " << distribution[A].getFrequency() << std::endl;
    std::cout << "B: " << distribution[B].getFrequency() << std::endl;
    std::cout << "C: " << distribution[C].getFrequency() << std::endl;
    std::cout << "D: " << distribution[D].getFrequency() << std::endl;
    std::cout << "E: " << distribution[E].getFrequency() << std::endl << std::endl;
    return;
}
