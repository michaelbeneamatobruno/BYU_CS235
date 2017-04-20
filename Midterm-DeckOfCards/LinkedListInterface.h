//YOU MAY NOT MODIFY THIS DOCUMENT
#pragma once
#include <string>

using namespace std;

template<typename T>
class LinkedListInterface
{

public:

	LinkedListInterface(void) {};
	virtual ~LinkedListInterface(void) {};

	virtual void insertHead(T value) = 0;

	virtual void insertTail(T value) = 0;

	virtual void insertAfter(T value, T insertionNode) = 0;

	virtual void remove(T value) = 0;

	virtual void clear() = 0;

	virtual T at(int index) = 0;

	virtual int size() = 0;

	virtual string printList() = 0;

};
