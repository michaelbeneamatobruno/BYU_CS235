#pragma once
#include "NodeInterface.h"
#include <iostream>

using namespace std;

class Node : public NodeInterface {

protected:
	Node *leftChild;
	Node *rightChild;
	int data;
	int height;

public:
	Node(int value);
	~Node();
	int getData() const;
	void setData(int newData);
	NodeInterface* getLeftChild() const;
	Node*& getLeft();
	NodeInterface* getRightChild() const;
	Node*& getRight();
	void setLeftChild(Node* ptr);
	void setRightChild(Node* ptr);
	int getHeight();
	void setHeight(int newHeight);
};
