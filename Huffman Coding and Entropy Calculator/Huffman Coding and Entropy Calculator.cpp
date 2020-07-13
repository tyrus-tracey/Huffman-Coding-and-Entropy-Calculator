/*
  Calculates and displays Huffman codes and entropy of user input string.
*/

#include <iostream>
#include <string>
#include "Helper.h"
#include "BinaryTree.h"

using namespace std;
bool running = true;
string inputString;

int main()
{
    cout << "Huffman Coding and Entropy Calculator\n";
    BinaryTree* tree = new BinaryTree;

    //TODO: convert inputDist into node formats to insert into tree.
    while(running) {
        cout << "Please enter an even input string of A-E up to 32 characters, or enter X to stop:\n";
        getline(cin, inputString); // Receive user input

        if (inputString != "X" && inputString != "x") {
            vector<int> charDistribution = readInputDistribution(inputString);
            displayDistribution(charDistribution);
        }
        else {
            running = false;
        }
    } 
    tree->printTree();
    delete tree;

    //check before close
    int i;
    cin >> i;
    cout << "\nClosing...\n";
    return 0;
}
