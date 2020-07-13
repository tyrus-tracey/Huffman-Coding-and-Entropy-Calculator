#pragma once
#include "Node.h"

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	int size() const;
	bool empty() const;
	Node* root();
	Node* position;

	void insertNode(Node* node);
	void printTree();
	void deleteTree(Node* node);

private:
	void printNode(Node* node);


	int treeSize;
	Node* rootNode;
};

