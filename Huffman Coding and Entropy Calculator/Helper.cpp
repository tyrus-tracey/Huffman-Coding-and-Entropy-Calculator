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

void removeZeroes(std::vector<Node>& distribution)
{
    std::vector<Node>::iterator iter = distribution.begin();
    while (iter != distribution.end()) {
        if (iter->getFrequency() == 0) {
            iter = distribution.erase(iter);
        }
        else {
            iter++;
        }
    }
    return;
}

// Parse string into chars and record frequencies
std::vector<Node> readInputDistributionSingle(std::string input) {
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
    removeZeroes(distribution);
    return distribution;
}

std::vector<Node> readInputDistributionDouble(std::string input)
{
    char temp1;
    char temp2;
    int index;
    std::vector<Node> distribution(25); //prog. doesn't know what to do here
    for (char temp1 = 'A'; temp1 <= 'E'; temp1++) {
        for (char temp2 = 'A'; temp2 <= 'E'; temp2++) {
            std::string jointSymbol = std::string() + temp1 + temp2;
            index = (temp1 % 65)*5 + temp2 % 65;
            distribution[index] = Node(jointSymbol, 0);
        }
    }

    std::stringstream inputStream(input);
    while (inputStream >> temp1 && inputStream >> temp2) {
        index = (temp1 % 65) * 5 + temp2 % 65;
        distribution[index]++;
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
void getEntropy(std::vector<Node> distribution)
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
    std::cout << "Entropy: " << entropy << std::endl;
}

// Print char frequencies
void displayDistribution(std::vector<Node> distribution) {
    std::vector<Node>::iterator iter = distribution.begin();
    while (iter != distribution.end()) {
        std::cout << (*iter).element() << ": " << (*iter).getFrequency() << std::endl;
        iter++;
    }
    std::cout << std::endl;
    return;
}
