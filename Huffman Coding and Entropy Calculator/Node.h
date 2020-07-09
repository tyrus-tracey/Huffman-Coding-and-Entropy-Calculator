#pragma once
class Node
{
public:
	Node(Node* parent, const char element);
	~Node();
	char element() const;
	Node* left() const;
	Node* right() const;
	Node* parent() const;
	bool isRoot() const;
	bool isExternal() const;

private:
	char data;
	Node* leftChild;
	Node* rightChild;	
	Node* parentNode;
};

