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
        cout << "\nPlease enter an even input string of A-E up to 32 characters, or enter X to stop:\n";
        getline(cin, inputString); // Receive user input

        if (inputString != "X" && inputString != "x") {
            if (inputString.length() % 2 == 0) {
                
                vector<Node> singleDistribution = readInputDistributionSingle(inputString);
                vector<Node> duoDistribution = readInputDistributionDouble(inputString);
                displayFirstEntropy(singleDistribution);
                displaySecondEntropy(duoDistribution);

                BinaryTree codeTree(singleDistribution);
                BinaryTree jointCodeTree(duoDistribution);
                codeTree.generateCodes();
                jointCodeTree.generateCodes();
                std::cout << "\nSingle-Symbol Tree:\n";
                codeTree.printTree();
                std::cout << "Avg Code Length: " << codeTree.averageCodeLength() << " bits per symbol." << endl;
                std::cout << "\nJoint-Symbol Tree:\n";
                jointCodeTree.printTree();
                std::cout << "Avg Code Length: " << jointCodeTree.averageCodeLength()/2 << " bits per symbol." << endl;
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
