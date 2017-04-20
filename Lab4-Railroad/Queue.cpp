#include "Queue.h"

using namespace std;

  Queue::Queue(){}
  Queue::~Queue(){}

  bool Queue::isEmpty()
  {
    Deque::isEmpty();
  }
  
  bool Queue::DuplicateChecking(int value)
  {
    return Deque::DuplicateChecking(value);
  }

  void Queue::pushBack(int value)
  {
    Deque::pushBack(value);
  }

  void Queue::popBack()
  {
    Deque::popBack();
  }

  int Queue::getFront()
  {
    return Deque::getFront();
  }

  int Queue::queueSize()
  {
    return Deque::dequeSize();
  }
