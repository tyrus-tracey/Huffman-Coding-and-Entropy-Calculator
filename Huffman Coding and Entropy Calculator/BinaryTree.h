#pragma once
#include "Node.h"

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	int size() const;
	bool empty() const;
	Node* root() const;
	Node* position;

private:
	int treeSize;
	Node* rootNode;
};

