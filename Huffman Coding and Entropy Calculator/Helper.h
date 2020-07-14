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

void initializeArray(T* array, int size);

std::vector<Node> readInputDistribution(std::string input);

std::vector<Node>::iterator findMin(std::vector<Node>& distribution);

int getSum(std::vector<Node> distribution);

void calculateFirstEntropy(std::vector<Node> distribution);

void displayDistribution(std::vector<Node> distribution);
