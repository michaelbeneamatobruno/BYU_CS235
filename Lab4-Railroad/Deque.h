#pragma once
#include "LinkedList.h"


using namespace std;

class Deque
{
protected:
  LinkedList myDeque;

public:
  Deque();
  ~Deque();

  bool isEmpty();

  bool DuplicateChecking(int value);
  
  void pushFront(int value);

  void pushBack(int value);

  void popFront();

  void popBack();

  int getFront();

  int getBack();

  int dequeSize();

  string toString() {
    stringstream ss;
    for (int i = 0; i < dequeSize(); i++) {
      ss << myDeque.at(i) << ",";
    }
    ss << endl;
    return ss.str();
  }

};
