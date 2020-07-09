#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	rootNode = new Node(nullptr, 'R');
	treeSize = 0;
	position = rootNode;
}

BinaryTree::~BinaryTree()
{
}

int BinaryTree::size() const
{
	return treeSize;	
}

bool BinaryTree::empty() const
{
	return (treeSize > 0 ? 0 : 1);
}

Node* BinaryTree::root() const
{
	return rootNode;
}
