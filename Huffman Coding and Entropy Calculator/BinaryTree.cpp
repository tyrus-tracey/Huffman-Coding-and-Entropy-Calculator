#include "BinaryTree.h"
#include "Helper.h"
#include <queue>
#include <iostream>

// Compare for lower-frequency node
struct CompareNodes{
	bool operator()(const Node node1, const Node node2)
	{
	return node1.getFrequency() > node2.getFrequency();
}
};

BinaryTree::BinaryTree(std::vector<Node> distribution)
	:treeSize(distribution.size()), rootNode(nullptr), position(rootNode)
{
	//Create vector of allocated node pointers
	std::vector<Node>::iterator iter = distribution.begin();
	std::priority_queue<Node*, std::vector<Node*>, CompareNodes> nodeQueue;
	std::vector<Node*> junkList;
	while (iter != distribution.end()) {
		Node* node = new Node(iter->element(), iter->getFrequency());
		nodeQueue.push(node);
		iter++;
	}

	// 1. Join smallest-frequency nodes to a parent
	// 2. Remove nodes from vector
	// 3. Append parent back to vector
	Node* left;
	Node* right;
	Node* parent;

	while (nodeQueue.size() > 1) {
		left = new Node(nodeQueue.top());
		junkList.push_back(nodeQueue.top());
		nodeQueue.pop();
		right = new Node(nodeQueue.top());
		junkList.push_back(nodeQueue.top());
		nodeQueue.pop();
		parent = new Node(left, right);
		nodeQueue.push(parent);
	}
	/*
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
	*/
	
	// Delete allocated nodes 
	std::vector<Node*>::iterator pNodeIterator = junkList.begin();
	while (pNodeIterator != junkList.end()) {
		delete *pNodeIterator;
		pNodeIterator++;
	}

	// Allocate one node representing root of Huffman tree
	if (!nodeQueue.empty()) {
		rootNode = new Node(nodeQueue.top()); 
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
	if (!node->isExternal()) {
		deleteTree(node->left());
		deleteTree(node->right());
	}
	delete node;
	return;
}

void BinaryTree::generateCodes()
{
	if (!empty()) {
		if (rootNode->isExternal()) {
			rootNode->appendCode("1");
		}
		generateCode(rootNode);
	}
}

double BinaryTree::averageCodeLength()
{
	if (!empty()) {
		return getCodeLength(rootNode);
	}
	else {
		return 0;
	}
}

void BinaryTree::generateCode(Node* node)
{
	if (node == nullptr || node == NULL) {
		return;
	}
	if (node->isExternal()) {
		return;
	}
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

double BinaryTree::getCodeLength(Node* node)
{
	if (node->isExternal()) {
		double prob = double(node->getFrequency()) / rootNode->getFrequency();
		return (prob * node->getCode().length());
	}

	double sum = getCodeLength(node->left()) + getCodeLength(node->right());
	return sum;
}

Node* BinaryTree::root() 
{
	return rootNode;
}
