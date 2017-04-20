#include <iostream>
#include "Deque.h"

using namespace std;

class Stack : public Deque

{
protected:

public:
  Stack();
  ~Stack();

  bool isEmpty();
  
  bool DuplicateChecking(int value);

  void pushFront(int value);

  void popFront();

  int getBack();

  int stackSize();
  
  string toString() {
    stringstream ss;
    for (int i = 0; i < myDeque.size(); i++) {
      ss << myDeque.at(i) << ",";
    }
    ss << endl;
    return ss.str();
  }

};
