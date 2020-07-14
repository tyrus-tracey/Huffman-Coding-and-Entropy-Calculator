/*
  Calculates and displays Huffman codes and entropy of user input string.
*/

#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "Helper.h"

using namespace std;
bool running = true;
string inputString;

int main()
{
    cout << "Huffman Coding and Entropy Calculator\n";

    //TODO: convert inputDist into node formats to insert into tree.
    while(running) {
        cout << "Please enter an even input string of A-E up to 32 characters, or enter X to stop:\n";
        getline(cin, inputString); // Receive user input

        if (inputString != "X" && inputString != "x") {
            vector<Node> charDistribution = readInputDistribution(inputString);
            displayDistribution(charDistribution);
            BinaryTree tree(charDistribution);
            tree.printTree();
        }
        else {
            running = false;
        }
    } 

    cout << "\nClosing...\n";
    return 0;
}
