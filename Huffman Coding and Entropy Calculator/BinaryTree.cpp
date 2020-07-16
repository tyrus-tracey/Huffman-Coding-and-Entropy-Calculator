#include "BinaryTree.h"
#include "Helper.h"
#include <iostream>

BinaryTree::BinaryTree(std::vector<Node> distribution)
	:treeSize(0), rootNode(nullptr), position(rootNode)
{
	std::vector<Node>::iterator iter = distribution.begin();
	std::vector<Node*> nodeList;
	while (iter != distribution.end()) {
		Node* node = new Node(iter->element(), iter->getFrequency());
		nodeList.push_back(node);
		iter++;
	}
	std::vector<Node*>::iterator treeNode;
	Node* left;
	Node* right;
	Node* parent;
	while(nodeList.size() > 1) { 
		treeNode = findMin(nodeList);
		left = new Node(*treeNode);
		nodeList.erase(treeNode); //  <- mem leak
		treeNode = findMin(nodeList);
		right = new Node(*treeNode);
		nodeList.erase(treeNode); // <- mem leak
		parent = new Node(left, right);
		nodeList.push_back(parent); 
	}
	rootNode = nodeList[0];
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
