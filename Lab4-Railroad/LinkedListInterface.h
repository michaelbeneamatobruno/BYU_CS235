//YOU MAY NOT MODIFY THIS DOCUMENT
#pragma once
#include <string>

using namespace std;

class LinkedListInterface
{

public:

	LinkedListInterface(void) {};
	virtual ~LinkedListInterface(void) {};

	virtual void insertHead(int value) = 0;

	virtual void insertTail(int value) = 0;

	virtual void insertAfter(int value, int insertionNode) = 0;

	virtual void remove(int value) = 0;

	// virtual void clear() = 0;

	virtual int at(int index) = 0;

	virtual int size() = 0;

	// virtual string printList() = 0;

};
