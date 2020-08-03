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
                //vector<Node> duoDistribution = readInputDistributionDouble(inputString);
                displayFirstEntropy(singleDistribution);
                //displaySecondEntropy(duoDistribution);

                BinaryTree codeTree(singleDistribution);
                //BinaryTree jointCodeTree(duoDistribution);
                codeTree.generateCodes();
                //jointCodeTree.generateCodes();
                std::cout << "Avg Single Code Length: " << codeTree.averageCodeLength() << " bits per symbol." << endl;
                //std::cout << "Avg Joint Code Length : " << jointCodeTree.averageCodeLength()/2 << " bits per symbol." << endl;
                std::cout << "Total Size: " << codeTree.totalSize() << " bits.\n";
                std::cout << "Single-Code Tree:\n";
                codeTree.printTree();
                //std::cout << "Joint-Code Tree:\n";
                //jointCodeTree.printTree();
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
