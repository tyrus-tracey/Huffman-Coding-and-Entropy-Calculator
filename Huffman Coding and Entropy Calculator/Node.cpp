#include "Node.h"

Node::Node(const std::string element, const int freq)
	:symbol(element), leftChild(nullptr), rightChild(nullptr), parentNode(nullptr), frequency(freq)
{
}

Node::Node(Node* parent, const std::string element, const int freq)
	:symbol(element), leftChild(nullptr), rightChild(nullptr), parentNode(parent), frequency(freq)
{
}

Node::~Node()
{
}

std::string Node::element() const
{
	return symbol;
}

int Node::getFrequency() const
{
	return frequency;
}

void Node::setFrequency(const int& value)
{
	frequency = value;
	return;
}

void Node::operator++(int)
{
	frequency++;
	return;
}

Node* Node::left() const
{
	return leftChild;
}

Node* Node::right() const
{
	return rightChild;
}

Node* Node::parent() const
{
	return parentNode;
}

void Node::deleteChildren()
{
	delete leftChild;
	delete rightChild;
	leftChild = nullptr;
	rightChild = nullptr;
	return;
}

void Node::setLeft(Node* node)
{
	leftChild = node;
	return;
}

void Node::setRight(Node* node)
{
	rightChild = node;
	return;
}

void Node::setParent(Node* node)
{
	parentNode = node;
	return;
}

bool Node::isRoot() const
{
	return false;
}

bool Node::isExternal() const
{
	return false;
}
