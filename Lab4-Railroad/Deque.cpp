#include "Deque.h"
#include <iostream>

using namespace std;

  Deque::Deque(){}
  Deque::~Deque()
  {
    // cout << "you're in the destructor" << endl;
    // myDeque.clear();
  }

  bool Deque::isEmpty()
  {
    if (dequeSize() == 0) {
      return true;
    }
    return false;
  }
  
  bool Deque::DuplicateChecking(int value)
  {
    if (myDeque.duplicateChecker(value)) {
      return true;
    }
    return false;
  }

  void Deque::pushFront(int value)
  {
    // cout << "deque push front" << endl;
    // cout << "Deque push front value is: " << value << endl;
    myDeque.insertHead(value);
    // cout << "my Deque at 0 is: " << myDeque.at(0) << endl;
  }

  void Deque::pushBack(int value)
  {
    // cout << "deque insert tail" << endl;
    myDeque.insertTail(value);
  }

  void Deque::popFront()
  {
    if (isEmpty()) {
      return;
    }
    // cout << "deque popfront" << endl;
    myDeque.remove(myDeque.at(0));
    return;
  }

  void Deque::popBack()
  {
    if (isEmpty()) {
      return;
    }
    // cout << "deque remove" << endl;
    myDeque.remove(myDeque.at(dequeSize() - 1));
    return;
  }

  int Deque::getFront()
  {
    // cout << "Deque::getFront()" << endl;
    if (isEmpty()) {
      return -1;
    }
    // cout << "Deque::size: " << dequeSize() << endl;
    // cout << "the front of the deque" << myDeque.at(0) << endl;
    return myDeque.at(0);
  }

  int Deque::getBack()
  {
    if (isEmpty()) {
      return -1;
    }
    // cout << "the end of the deque" << endl;
    return myDeque.at(dequeSize() - 1);
  }

  int Deque::dequeSize()
  {
    // cout << "Deque size" << endl;
    return myDeque.size();
  }
  
