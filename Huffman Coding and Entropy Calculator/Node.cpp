#include "Node.h"

Node::Node(Node* parent, const char element)
	:data(element), leftChild(nullptr), rightChild(nullptr), parentNode(parent)
{
}

Node::~Node()
{
}

char Node::element() const
{
	return data;
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

bool Node::isRoot() const
{
	return false;
}

bool Node::isExternal() const
{
	return false;
}
