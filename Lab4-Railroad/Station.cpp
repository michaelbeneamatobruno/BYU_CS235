#pragma once
#include <iostream>
#include "Station.h"

using namespace std;

	Station::Station(){}
	Station::~Station(){}

	bool Station::StationIsEmpty()
	{
		if (currentCar == EMPTY_CAR) {
			return true;
		}
		return false;
	}

	bool Station::StackDuplicate(int car)
	{
		if (showSizeOfStack() == 0) {
			return false;
		}
		if (myStack.DuplicateChecking(car)) {
			return true;
		}
		return false;
	}

	bool Station::QueueDuplicate(int car)
	{
		if (showSizeOfQueue() == 0) {
			return false;
		}
		if (myQueue.DuplicateChecking(car)) {
			return true;
		}
		return false;
	}

	bool Station::DequeDuplicate(int car)
	{
		if (showSizeOfDeque() == 0) {
			return false;
		}
		if (myDeque.DuplicateChecking(car)) {
			return true;
		}
		if (IRDeque.DuplicateChecking(car)) {
			return true;
		}
		if (ORDeque.DuplicateChecking(car)) {
			return true;
		}
		return false;
	}

	bool Station::addToStation(int car)
	{
		if (currentCar != EMPTY_CAR) {
			cout << "Error: There is already a car in the station" << endl;
			return false;
		}
		if (StackDuplicate(car)) {
		 cout << "Error: Value already exists in stack" << endl;
		 return false;
		}
		if (QueueDuplicate(car)) {
		 cout << "Error: Value already exists in queue" << endl;
		 return false;
		}
		if (DequeDuplicate(car)) {
		 cout << "Error: Value already exists in one of the deques" << endl;
		 return false;
		}
		if (car < 0) {
			cout << "Error: The car ID is negative" << endl;
			return false;
		}
		currentCar = car;
		// cout << "myStack.toString() (Station): " << myStack.toString() << endl;
		return true;
	}

	int Station::showCurrentCar()
	{
		if (currentCar == EMPTY_CAR) {
			return EMPTY_CAR;
		}
		return currentCar;
	}

	bool Station::removeFromStation()
	{
		if (currentCar == EMPTY_CAR) {
			cout << "Error: station is already empty" << endl;
			return false;
		}
		currentCar = EMPTY_CAR;
		return true;
	}

	bool Station::addToStack()
	{
		if (showSizeOfStack() == FULL_STRUCT) {
			cout << "Error: the stack is already full" << endl;
			return false;
		}
		if (currentCar == EMPTY_CAR) {
			cout << "Error: There is no car in the station" << endl;
			return false;
		}
		// cout << "currentCar is: " << currentCar << endl;
		myStack.pushFront(currentCar);
		currentCar = EMPTY_CAR;
		// cout << "currentCar is: " << currentCar << endl;
		// cout << "top of stack is: " << showTopOfStack() << endl;
		return true;
	}

	bool Station::removeFromStack()
	{
		if (myStack.isEmpty()) {
			cout << "Error: Stack is empty" << endl;
			return false;
		}
		if (currentCar != EMPTY_CAR) {
			cout << "Error: Already current car" << endl;
			return false;
		}
		currentCar = showTopOfStack();
		myStack.popFront();
		return true;
	}

	int Station::showTopOfStack()
	{
		// cout << "showTopOfStack()" << endl;
		return myStack.getFront();
	}

	int Station::showSizeOfStack()
	{
		// cout << "Station::showSizeOfStack()" << endl;
		return myStack.stackSize();
	}

	bool Station::addToQueue()
	{
		if (currentCar == EMPTY_CAR) {
			cout << "Error: There is no car in the station" << endl;
			return false;
		}
		if (myQueue.queueSize() == FULL_STRUCT) {
			cout << "Error: The queue is already full" << endl;
			return false;
		}
		myQueue.pushFront(currentCar);
		currentCar = EMPTY_CAR;
		return true;
	}

	bool Station::removeFromQueue()
	{
		if (currentCar != EMPTY_CAR) {
			cout << "Error: there is already a car in the station" << endl;
			return false;
		}
		if (myQueue.isEmpty()) {
			cout << "Error: the queue is empty" << endl;
			return false;
		}
		cout << "The car has been removed from the queue and added to the station" << endl;
		currentCar = myQueue.getBack();
		myQueue.popBack();
		return true;
	}

	int Station::showTopOfQueue()
	{
		return myQueue.getBack();
	}

	int Station::showSizeOfQueue()
	{
		return myQueue.queueSize();
	}

	bool Station::addToDequeLeft()
	{
		if (currentCar == EMPTY_CAR) {
			cout << "Error: There is no car in the station" << endl;
			return false;
		}
		if (myDeque.dequeSize() == FULL_STRUCT) {
			cout << "Error: The deque is already full" << endl;
			return false;
		}
		myDeque.pushBack(currentCar);
		currentCar = EMPTY_CAR;
		return true;
	}

	bool Station::addToDequeRight()
	{
		if (currentCar == EMPTY_CAR) {
			cout << "Error: There is no car in the station" << endl;
			return false;
		}
		if (myDeque.dequeSize() == FULL_STRUCT) {
			cout << "Error: The deque is already full" << endl;
			return false;
		}
		myDeque.pushFront(currentCar);
		currentCar = EMPTY_CAR;
		return true;
	}

	bool Station::removeFromDequeLeft()
	{
		if (myDeque.isEmpty() || currentCar != EMPTY_CAR) {
			return false;
		}
		currentCar = showTopOfDequeLeft();
		myDeque.popBack();
		return true;
	}

	bool Station::removeFromDequeRight()
	{
		if (myDeque.isEmpty() || currentCar != EMPTY_CAR) {
			return false;
		}
		currentCar = showTopOfDequeLeft();
		myDeque.popFront();
		return true;
	}

	int Station::showTopOfDequeLeft()
	{
		return myDeque.getBack();
	}

	int Station::showTopOfDequeRight()
	{
		return myDeque.getFront();
	}

	int Station::showSizeOfDeque()
	{
		return myDeque.dequeSize();
	}
	
	//Input-Restricted Deque----------------------------------------------
	bool Station::addToIRDequeLeft()
	{
		if (currentCar == EMPTY_CAR) {
		cout << "Error: There is no car in the station" << endl;
		return false;
		}
		if (IRDeque.dequeSize() == FULL_STRUCT) {
			cout << "Error: The deque is already full" << endl;
			return false;
		}
		IRDeque.pushFront(currentCar);
		currentCar = EMPTY_CAR;
		// cout << ORDeque.toString() << endl;
		return true;
	}
	
	bool Station::removeFromIRDequeLeft()
	{
		if (IRDeque.isEmpty() || currentCar != EMPTY_CAR) {
			return false;
		}
		currentCar = showTopOfIRDequeLeft();
		IRDeque.popBack();
		return true;
	}

	bool Station::removeFromIRDequeRight()
	{
		if (IRDeque.isEmpty() || currentCar != EMPTY_CAR) {
			return false;
		}
		currentCar = showTopOfIRDequeRight();
		IRDeque.popFront();
		return true;
	}

	int Station::showTopOfIRDequeLeft()
	{
		return IRDeque.getBack();
	}

	int Station::showTopOfIRDequeRight()
	{
		return IRDeque.getFront();
	}

	int Station::showSizeOfIRDeque()
	{
		return IRDeque.dequeSize();
	}

	//Output-Restricted Deque---------------------------------------------
	bool Station::addToORDequeLeft()
	{
		if (currentCar == EMPTY_CAR) {
			cout << "Error: There is no car in the station" << endl;
		return false;
		}
		if (ORDeque.dequeSize() == FULL_STRUCT) {
			cout << "Error: The deque is already full" << endl;
		return false;
		}
		ORDeque.pushFront(currentCar);
		currentCar = EMPTY_CAR;
		cout << ORDeque.toString() << endl;
		return true;
	} 

	bool Station::addToORDequeRight()
	{
		if (currentCar == EMPTY_CAR) {
			cout << "Error: There is no car in the station" << endl;
			return false;
		}
		if (ORDeque.dequeSize() == FULL_STRUCT) {
			cout << "Error: The deque is already full" << endl;
			return false;
		}
		ORDeque.pushBack(currentCar);
		currentCar = EMPTY_CAR;
		// cout << ORDeque.toString() << endl;
		return true;
	}

	bool Station::removeFromORDequeLeft()
	{
		if (ORDeque.isEmpty() || currentCar != EMPTY_CAR) {
			return false;
		}
		currentCar = showTopOfORDequeLeft();
		ORDeque.popBack();
		return true;
	}

	int Station::showTopOfORDequeLeft()
	{
		return ORDeque.getBack();
	}

	int Station::showSizeOfORDeque()
	{
		return ORDeque.dequeSize();
	}