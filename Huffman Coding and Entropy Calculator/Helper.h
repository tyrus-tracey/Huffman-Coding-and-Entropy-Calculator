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

void removeZeroes(std::vector<Node>& distribution);

std::vector<Node> readInputDistributionSingle(std::string input);

std::vector<Node> readInputDistributionDouble(std::string input);

std::vector<Node>::iterator findMin(std::vector<Node>& distribution);

int getSum(std::vector<Node> distribution);

void getEntropy(std::vector<Node> distribution);

void displayDistribution(std::vector<Node> distribution);
