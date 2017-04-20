#include "Stack.h"


using namespace std;

  Stack::Stack(){}
  Stack::~Stack(){}

  bool Stack::isEmpty()
  {
    return Deque::isEmpty();
  }
  
  bool Stack::DuplicateChecking(int value)
  {
    return Deque::DuplicateChecking(value);
  }

  void Stack::pushFront(int value)
  {
    // cout << "push Front value is: " << value << endl;
    Deque::pushFront(value);
    // cout << "my Deque in stack: " << myDeque.at(0) << endl;
  }

  void Stack::popFront()
  {
    Deque::popFront();
  }

  int Stack::getBack()
  {
    // cout << "Stack::getFront()" << endl;
    return Deque::getBack();
  }

  int Stack::stackSize()
  {
    // cout << "Stack::stackSize()" << endl;
    return Deque::dequeSize();
  }
