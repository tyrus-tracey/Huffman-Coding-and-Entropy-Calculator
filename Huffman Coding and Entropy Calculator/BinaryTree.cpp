#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree()
	:treeSize(0), rootNode(new Node("oldROOT", 0)), position(rootNode)
{

}

BinaryTree::~BinaryTree()
{
	deleteTree(rootNode);
	return;
}

int BinaryTree::size() const
{
	return treeSize;	
}

bool BinaryTree::empty() const
{
	return treeSize <= 0;
}

// Adds a node to the tree
// Tree root and inserted node become children of a new root (of junk symbol and summed freq.)
void BinaryTree::insertNode(Node* node)
{
	if (empty()) {
		rootNode = node;
		treeSize++;
		return;
	}

	Node* newRoot = new Node("ROOT", node->getFrequency() + rootNode->getFrequency());
	if (node->getFrequency() <= rootNode->getFrequency()) {
		newRoot->setLeft(rootNode);
		newRoot->setRight(node);
	}
	else {
		newRoot->setLeft(node);
		newRoot->setRight(rootNode);
	}
	node->setParent(newRoot);
	rootNode->setParent(newRoot);
	rootNode = newRoot;

	treeSize++;
}

void BinaryTree::printTree()
{
	printNode(rootNode);
	return;
}

void BinaryTree::printNode(Node* node) {
	if (node == nullptr) {
		return;
	}
	printNode(node->left());
	printNode(node->right());
	std::cout << node->element() << ": " << node->getFrequency() << std::endl;
	return;
}

void BinaryTree::deleteTree(Node* node) {
	if (node == nullptr) {
		return;
	}
	deleteTree(node->left());
	deleteTree(node->right());
	delete node;
	return;
}

Node* BinaryTree::root() 
{
	return rootNode;
}
