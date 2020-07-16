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

    while(running) {
        cout << "Please enter an even input string of A-E up to 32 characters, or enter X to stop:\n";
        getline(cin, inputString); // Receive user input

        if (inputString != "X" && inputString != "x") {
            if (inputString.length() % 2 == 0) {
                /*
                //First Entropy
                vector<Node> singleDistribution = readInputDistributionSingle(inputString);
                displayDistribution(singleDistribution);
                calculateFirstEntropy(singleDistribution);
                BinaryTree tree(singleDistribution);
                tree.printTree();
                */


                //Second Entropy
                vector<Node> duoDistribution = readInputDistributionDouble(inputString);
                removeZeroes(duoDistribution);
                displayDistribution(duoDistribution);
            }
            else {
                cout << "Error: Please enter a string of even length." << endl;
            }
        }
        else {
            running = false;
        }
    } 

    cout << "\nClosing...\n";
    return 0;
}
