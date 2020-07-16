#pragma once
#include "Node.h"
#include <vector>

class BinaryTree
{
public:
	BinaryTree(std::vector<Node> distribution);
	~BinaryTree();
	int size() const;
	bool empty() const;
	Node* root();
	Node* position;
	void printTree();
	void deleteTree(Node* node);
	void generateCodes();

private:
	void generateCode(Node* node);
	void printNode(Node* node);

	int treeSize;
	Node* rootNode;
};

