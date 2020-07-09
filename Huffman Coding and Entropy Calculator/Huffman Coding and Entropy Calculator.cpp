// Huffman Coding and Entropy Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Helper.h"

using namespace std;
bool running = true;
char temp;
string inputString;

int main()
{
    int charDistribution[5];
    cout << "Huffman Coding and Entropy Calculator\n";

    while(running) {
        initializeArray(charDistribution, 5);
        cout << "Please enter an even input string of A-E up to 32 characters, or enter X to stop:\n";
        getline(cin, inputString); // Receive user input

        if (inputString == "X" || inputString == "x") {
            running = false;
        }
        else {
            readInputDistribution(inputString, charDistribution);
            displayDistribution(charDistribution);
        }
    } 

    cout << "\nClosing...\n";
    return 0;
}
