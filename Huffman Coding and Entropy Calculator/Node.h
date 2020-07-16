#pragma once
#include <string>

class Node
{
public:
	Node();
	Node(Node* node);
	Node(const std::string element, const int freq);
	Node(Node* parent, const std::string element, const int freq);
	Node(Node* lChild, Node* rChild);
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
	std::string getCode();
	void appendCode(std::string string);
	bool isRoot() const;
	bool isExternal() const;

private:
	std::string symbol;
	int frequency;
	std::string code = "";
	Node* leftChild;
	Node* rightChild;	
	Node* parentNode;
};

