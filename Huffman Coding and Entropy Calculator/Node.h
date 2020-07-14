#pragma once
#include <string>

class Node
{
public:
	Node(const std::string element, const int freq);
	Node(Node* parent, const std::string element, const int freq);
	~Node();
	std::string element() const;
	int getFrequency() const;
	void setFrequency(const int& value);
	void operator++(int);
	Node* left() const;
	Node* right() const;
	Node* parent() const;
	void deleteChildren();
	void setLeft(Node* node);
	void setRight(Node* node);
	void setParent(Node* node);
	bool isRoot() const;
	bool isExternal() const;

private:
	std::string symbol;
	int frequency;
	Node* leftChild;
	Node* rightChild;	
	Node* parentNode;
};

