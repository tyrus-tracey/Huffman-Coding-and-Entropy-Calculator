#include "BinaryTree.h"
#include "Helper.h"
#include <iostream>

BinaryTree::BinaryTree(std::vector<Node> distribution)
	:treeSize(0), rootNode(nullptr), position(rootNode)
{
	while (!distribution.empty()) {
		std::vector<Node>::iterator iter = findMin(distribution);
		insertNode(*iter);
		distribution.erase(iter);
	}
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
void BinaryTree::insertNode(Node node)
{
	if (empty()) {
		rootNode = new Node(node.element(), node.getFrequency());
		treeSize++;
		return;
	}

	Node* newRoot = new Node("ROOT", node.getFrequency() + rootNode->getFrequency());
	Node* newNode = new Node(node.element(), node.getFrequency());
	if (node.getFrequency() <= rootNode->getFrequency()) {
		newRoot->setLeft(rootNode);
		newRoot->setRight(newNode);
	}
	else {
		newRoot->setLeft(newNode);
		newRoot->setRight(rootNode);
	}
	newNode->setParent(newRoot);
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
