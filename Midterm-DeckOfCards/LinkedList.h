#pragma once
#include "LinkedListInterface.h"
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface <T>
{

protected:
  struct node
  {
  	T value;
  	node* nextNode;
    node* previous;
  	node(T& value, node* nextNode = NULL, node* previous = NULL) {
  	    this->value = value;
  	    this->nextNode = nextNode;
        this->previous = previous;
  	}
  };

  node* lastNode = NULL;
  node* firstNode = NULL;
  int listSize = 0;

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
    node* current = NULL;
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
  	// if (duplicateChecker(value)) {
  	// 	return;
  	// }

    node* current = NULL;
  	if (firstNode == NULL) {
  		current = new node(value);
  		firstNode = current;
      lastNode = current;
  		return;
  	}
  	else {
  		current = new node(value, firstNode);
      firstNode->previous = current;
  		firstNode = current;
  		return;
  	}
  }
  void insertTail(T value)
  {
  	// if (duplicateChecker(value)) {
  	// 	return;
  	// }

    node* current = NULL;
    node* temp = NULL;
  	current = firstNode;
  	if (current == NULL) {
  		insertHead(value);
  	}
  	else {
      temp = new node(value, NULL, lastNode);
  		temp->previous->nextNode = temp;
      lastNode = temp;
      return;
  		// while (current->nextNode != NULL) {
      // current = current->nextNode;
  		// }
      //
  		// temp = new node(value);
  		// current->nextNode = temp;
      // lastNode = temp;
  		// return;
  	}
  }
  void insertAfter(T value, T insertionNode)
  {
  	// if (duplicateChecker(value)) {
  	// 	return;
  	// }

    node* current = NULL;
    node* temp = NULL;
  	current = firstNode;
  	while (current != NULL) {
  		if (current->value == insertionNode) {
        if (current == lastNode) {
          insertTail(value);
          return;
        }
  			temp = new node(value, current->nextNode, current);
        current->nextNode->previous = temp;
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

    node* current = NULL;
    node* temp = NULL;
  	current = firstNode;
  	if (current->value == value) {
      if (current == lastNode) {
        lastNode = NULL;
      }
  		firstNode = current->nextNode;
  		delete current;
  		return;
  	}
  	while (current != NULL) {
  		if (current->nextNode->value == value) {
  			temp = current->nextNode;
        if (temp == lastNode) {
          lastNode = current;
        }
  			current->nextNode = temp->nextNode;
  			delete temp;
  			return;
  		}
  		current = current->nextNode;
  	}
  }
  void removeFromEnd(T value)
  {
    if (duplicateChecker(value) == false) {
  		return;
  	}

    node* current = NULL;
    node* temp = NULL;
  	current = lastNode;
  	if (current->value == value) {
      if (current == firstNode) {
        firstNode = NULL;
        lastNode = NULL;
        delete current;
        return;
      }
  		lastNode = current->previous;
      lastNode->nextNode = NULL;
  		delete current;
  		return;
  	}
  	while (current != NULL) {
  		if (current->previous->value == value) {
  			temp = current->previous;
        if (temp == firstNode) {
          firstNode = current;
          firstNode->previous = NULL;
          delete temp;
          return;
        }
  			current->previous = temp->previous;
        current->previous->nextNode = current;
  			delete temp;
  			return;
  		}
  		current = current->previous;
  	}

  }
  void clear()
  {
    node* current = NULL;
  	current = firstNode;
  	while (firstNode != NULL) {
  		current = firstNode;
  		firstNode = current->nextNode;
  		delete current;
  	}
  }
  T at(int index)
  {
    node* current = NULL;
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
  T atFromEnd(int index)
  {
    int size = 0;
    size = LinkedList::size() - 1;
    index = size - index;
    node* current = NULL;
  	current = lastNode;
  	if (index < 0) {
  		throw std::out_of_range("under 9000");
  	}
  	for (int i = 0; i < index; i++) {
  		if (current == NULL) {
  			throw std::out_of_range("OVER 9000");
  		}
  		if (i == (index - 1)) {
  			return current->value;
  		}
  		current = current->previous;
  	}
  }
  int size()
  {
    node* current = NULL;
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

    node* current = NULL;
  	current = firstNode;
  	if (current == NULL) {
  		return list;
  	}
  	else {
  	   while (current->nextNode != NULL) {
  			out << current->value;
  			out << ", ";
  			current = current->nextNode;
  	   }
    out << current->value;
  	list = out.str();
  	return list;
  	}
  }
};
