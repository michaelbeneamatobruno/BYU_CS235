#pragma once
#include <iostream>
#include <string>
#include "StationInterface.h"
#include "LinkedList.h"
#include "Deque.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

class Station : public StationInterface
{
protected:
	const int EMPTY_CAR = -1;
	const int FULL_STRUCT = 5;
	int currentCar = EMPTY_CAR;
	Deque IRDeque;
	Deque ORDeque;
	Deque myDeque;
	Queue myQueue;
	Stack myStack;


public:
	Station();
	~Station();
	
	string toStringStack() {
		return myStack.toString();
	}

	bool StationIsEmpty();

	bool StackDuplicate(int car);

	bool QueueDuplicate(int car);

	bool DequeDuplicate(int car);

	bool addToStation(int car);

	int showCurrentCar();

	bool removeFromStation();

	bool addToStack();

	bool removeFromStack();

	int showTopOfStack();

	int showSizeOfStack();

	bool addToQueue();

	bool removeFromQueue();

	int showTopOfQueue();

	int showSizeOfQueue();

	bool addToDequeLeft();

	bool addToDequeRight();

	bool removeFromDequeLeft();

	bool removeFromDequeRight();

	int showTopOfDequeLeft();

	int showTopOfDequeRight();

	int showSizeOfDeque();
	
	bool addToIRDequeLeft();

	bool removeFromIRDequeLeft();

	bool removeFromIRDequeRight();

	int showTopOfIRDequeLeft();

	int showTopOfIRDequeRight();

	int showSizeOfIRDeque();

	bool addToORDequeLeft();

	bool addToORDequeRight();

	bool removeFromORDequeLeft();

	int showTopOfORDequeLeft();

	int showSizeOfORDeque();

};
