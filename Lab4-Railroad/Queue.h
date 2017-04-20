#include <iostream>
#include "Deque.h"

using namespace std;

class Queue : public Deque

{
protected:

public:
  Queue();
  ~Queue();

  bool isEmpty();
  
  bool DuplicateChecking(int value);

  void pushBack(int value);

  void popBack();

  int getFront();

  int queueSize();

};
