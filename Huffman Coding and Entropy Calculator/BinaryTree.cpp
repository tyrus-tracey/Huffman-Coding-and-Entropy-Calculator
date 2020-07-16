#include "BinaryTree.h"
#include "Helper.h"
#include <iostream>

BinaryTree::BinaryTree(std::vector<Node> distribution)
	:treeSize(0), rootNode(nullptr), position(rootNode)
{
	//Create vector of allocated node pointers
	std::vector<Node>::iterator iter = distribution.begin();
	std::vector<Node*> nodeList;
	std::vector<Node*> junkList;
	while (iter != distribution.end()) {
		Node* node = new Node(iter->element(), iter->getFrequency());
		nodeList.push_back(node);
		iter++;
	}

	// 1. Join smallest-frequency nodes to a parent
	// 2. Remove nodes from vector
	// 3. Append parent back to vector
	std::vector<Node*>::iterator treeNode;
	Node* left;
	Node* right;
	Node* parent;
	while(nodeList.size() > 1) { 
		treeNode = findMin(nodeList);
		left = new Node(*treeNode);
		junkList.push_back(*treeNode);
		nodeList.erase(treeNode); 
		treeNode = findMin(nodeList);
		right = new Node(*treeNode);
		junkList.push_back(*treeNode);
		nodeList.erase(treeNode); 
		parent = new Node(left, right);
		nodeList.push_back(parent); 
	}
	
	// Delete allocated nodes
	treeNode = junkList.begin();
	while (treeNode != junkList.end()) {
		delete *treeNode;
		treeNode++;
	}

	// Allocate one node representing root of Huffman tree
	rootNode = new Node(nodeList[0]); //segfault if empty string
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
	std::cout << node->element() << ": " << node->getFrequency() << " " << node->getCode() << std::endl;
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

void BinaryTree::generateCodes()
{
	generateCode(rootNode);
}

void BinaryTree::generateCode(Node* node)
{
	if (node->left() != nullptr) {
		node->left()->appendCode(node->getCode() + '1');
		generateCode(node->left());
	}
	if (node->right() != nullptr) {
		node->right()->appendCode(node->getCode() + '0');
		generateCode(node->right());
	}
	return;
}

Node* BinaryTree::root() 
{
	return rootNode;
}
