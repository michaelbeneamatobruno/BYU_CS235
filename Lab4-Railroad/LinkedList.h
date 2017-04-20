#pragma once
#include "LinkedListInterface.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

class LinkedList : public LinkedListInterface
{
protected:

    struct node
    {
    	int value;
    	node* nextNode;

    	node(int& value, node* address = NULL) {
    	    this->value = value;
    	    nextNode = address;
    	}
    };

    node* firstNode = NULL;
    node* current = NULL;
    int listSize = 0;
    // int clearSize = 0;

public:

    LinkedList()
    {
    	firstNode = NULL;
    }
    ~LinkedList()
    {
    	// cout << "you're in the LL destructor" << endl;
    	clear();
    }

    bool duplicateChecker(int value)
    {
    	current = firstNode;
    	while (current != NULL) {
    		if (current->value == value) {
    			return true;
    		}
    		current = current->nextNode;
    	}
    	return false;
    }

	void insertHead(int value)
	{
		if (duplicateChecker(value)) {
			return;
		}
		if (firstNode == NULL) {
			firstNode = new node(value);
			return;
		}
		else {
			firstNode = new node(value, firstNode);
			return;
		}
	}

	void insertTail(int value)
	{
		if (duplicateChecker(value)) {
			return;
		}
		
		node* temp = NULL;
		current = firstNode;
		if (current == NULL) {
			insertHead(value);
		}
		else {
			while (current->nextNode != NULL) {
		 		current = current->nextNode;
			}
			temp = new node(value);
			current->nextNode = temp;
			return;
		}
	}

	void insertAfter(int value, int insertionNode)
	{
		if (duplicateChecker(value)) {
			return;
		}
	
		node* temp = NULL;
		current = firstNode;
		while (current != NULL) {
			if (current->value == insertionNode) {
				temp = new node(value, current->nextNode);
				current->nextNode = temp;
				return;
			}
			current = current->nextNode;
		}
	}

	void remove(int value)
	{
		if (duplicateChecker(value) == false) {
			return;
		}
		
		current = firstNode;
		if (current->value == value) {
			firstNode = current->nextNode;
			delete current;
			current = NULL;
			return;
		}
		
		node* temp = NULL;
		while (current != NULL) {
			if (current->nextNode->value == value) {
				temp = current->nextNode;
				current->nextNode = temp->nextNode;
				delete temp;
				temp = NULL;
				return;
			}
			current = current->nextNode;
		}
	}

	void clear()
	{
		current = firstNode;
		// cout << "set current = firstNode" << endl;
		while (firstNode != NULL && current != NULL) {
			// cout << "enter while loop" << endl;
			current = firstNode;
			// cout << "current is set back to firstNode" << endl;
			firstNode = current->nextNode;
			// cout << "firstnode is current->nextNode" << endl;
			delete current;
			// cout << "delete current" << endl;
			current = NULL;
			// cout << "set current = NULL" << endl;
		}
	}

	int at(int index)
	{

		current = firstNode;
		if (index < 0) {
			throw std::out_of_range("under 9000");
		}
		for (int i = 0; i <= index; i++) {
			if (current == NULL) {
				throw std::out_of_range("OVER 9000");
			}
			else if (i == index) {
				return current->value;
			}
			current = current->nextNode;
		}
	}

	int size()
	{
		current = firstNode;
		listSize = 0;
		while (current != NULL) {
			listSize += 1;
			current = current->nextNode;
		}
		return listSize;
	}

	// string printList()
	// {
	// 	string list;
	// 	ostringstream out;

	// 	current = firstNode;
	// 	if (current == NULL) {
	// 		return list;
	// 	}
	// 	else {
	// 		while (current != NULL) {
	// 			out << current->value;
	// 			out << " ";
	// 			current = current->nextNode;
	// 	}

	// 	list = out.str();
	// 	return list;
	// 	}
	// }
};
