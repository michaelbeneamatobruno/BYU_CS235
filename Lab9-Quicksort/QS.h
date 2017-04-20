#pragma once
#include "QSInterface.h"
#include <sstream>

using namespace std;

class QS : public QSInterface
{
protected:
  int currentIndex;
  int maxCapacity;
  int* myArray;
  bool arrayIsEmpty;
public:
	QS();
	~QS();
  void swap(int leftIndex, int rightIndex);
  void sort(int leftIndex, int rightIndex);
	void sortAll();
	int medianOfThree(int left, int right);
	int partition(int left, int right, int pivotIndex);
	string getArray() const;
	int getSize() const;
	bool addToArray(int value);
	bool createArray(int capacity);
	void clear();
};
