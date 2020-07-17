#include "Node.h"


Node::Node()
	:symbol(""), leftChild(nullptr), rightChild(nullptr), parentNode(nullptr), frequency(0)
{

}

Node::Node(Node* node)
	:symbol(node->element()), frequency(node->getFrequency())
{
	if (node->left() != nullptr) {
		leftChild = node->left();
		leftChild->parentNode = this;
	}
	if (node->right() != nullptr) {
		rightChild = node->right();
		rightChild->parentNode = this;
	}
}

Node::Node(const std::string element, const int freq)
	:symbol(element), leftChild(nullptr), rightChild(nullptr), parentNode(nullptr), frequency(freq)
{
}

Node::Node(Node* parent, const std::string element, const int freq)
	:symbol(element), leftChild(nullptr), rightChild(nullptr), parentNode(parent), frequency(freq)
{
}

Node::Node(Node* lChild, Node* rChild)
	: symbol("P"), frequency(lChild->frequency + rChild->frequency), parentNode(nullptr)
{
	leftChild = lChild;
	rightChild = rChild;
	leftChild->parentNode = this;
	rightChild->parentNode = this;
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

std::string Node::getCode()
{
	return code;
}

void Node::appendCode(std::string string)
{
	code += string;
	return;
}

bool Node::isRoot() const
{
	return(parentNode == nullptr ? true : false);
}

bool Node::isExternal() const
{
	if (symbol != "P") {
		return true;
	}
	if (leftChild == NULL & rightChild == NULL) {
		return true;
	}
	if (leftChild == nullptr && rightChild == nullptr) {
		return true;
	}
	return false;
}
