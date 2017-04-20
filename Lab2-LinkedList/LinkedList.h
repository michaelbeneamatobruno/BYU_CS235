#pragma once
#include "LinkedListInterface.h"
#include <string>
#include <sstream>

using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface <T>
{
	
    protected:
    struct node
    {
    	T value;
    	node* nextNode;
    	
    	node(T& value, node* address = NULL) {
    	    this->value = value;
    	    nextNode = address;
    	}
    };
    
    node* firstNode = NULL;
    node* current = NULL;
    node* temp = NULL;
    int listSize = 0;
    int clearSize = 0;
    
    public:
    
    LinkedList()
    {
    	firstNode = NULL;
    }
    ~LinkedList() 
    {
    	clear();
    	
    }
    
    
    
    
    bool duplicateChecker(T value)
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
    
    
	void insertHead(T value)
	{
		if (duplicateChecker(value)) {
			return;
		}
		if (firstNode == NULL) {
			current = new node(value);
			firstNode = current;
			return;
		}
		else {
			current = new node(value, firstNode);
			firstNode = current;
			return;
		}
	}
	
	
	void insertTail(T value)
	{
		if (duplicateChecker(value)) {
			return;
		}
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
	
	
	void insertAfter(T value, T insertionNode)

	{
		if (duplicateChecker(value)) {
			return;
		}
		
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
	
	
	void remove(T value)
	{
		if (duplicateChecker(value) == false) {
			return;
		}
		
		current = firstNode;
		if (current->value == value) {
			firstNode = current->nextNode;
			delete current;
			return;
		}
		while (current != NULL) {
			if (current->nextNode->value == value) {
				temp = current->nextNode;
				current->nextNode = temp->nextNode;
				delete temp;
				return;
			}
			current = current->nextNode;
		}
	}


	void clear()
	{
		current = firstNode;
		while (firstNode != NULL) {
			current = firstNode;
			firstNode = current->nextNode;
			delete current;
		}
	}


	T at(int index)
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
	
	string printList()
	{
		string list;
		ostringstream out;
		
		current = firstNode;
		if (current == NULL) {
			return list;
		}
		else {
			while (current != NULL) {
				out << current->value;
				out << " ";
				current = current->nextNode;
		}

		list = out.str();
		return list;
		}
	}
};