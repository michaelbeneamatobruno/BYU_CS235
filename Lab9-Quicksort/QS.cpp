#include "QS.h"

using namespace std;

QS::QS() {
  myArray = NULL;
}
QS::~QS() {
  clear();
}
void QS::swap(int leftIndex, int rightIndex) {
  int temp = myArray[leftIndex];
  myArray[leftIndex] = myArray[rightIndex];
  myArray[rightIndex] = temp;
}
void QS::sort(int leftIndex, int rightIndex) {
  if (rightIndex - leftIndex == 1) {
    if (myArray[rightIndex] > myArray[leftIndex]) {
      return;
    }
    swap(leftIndex, rightIndex);
  }
  else if (rightIndex - leftIndex == 0) {
    return;
  }
  else {
    if (leftIndex < 0 || rightIndex > currentIndex - 1 || rightIndex < leftIndex || leftIndex > rightIndex) {
      return;
    }
    int middle = medianOfThree(leftIndex, rightIndex);
    int partValue = partition(leftIndex, rightIndex, middle);
    sort(leftIndex, partValue - 1);
    sort(partValue + 1, rightIndex);
  }
}
void QS::sortAll() {
  sort(0, currentIndex - 1);
}
int QS::medianOfThree(int left, int right) {
  if (arrayIsEmpty || left >= right || left < 0 || right >= currentIndex) {
    return -1;
  }
  int middle = (left + right) / 2;
  int numElements = 3;
  int temp = 0;
  for (int i = 0; i <= numElements; i++) {
    if (myArray[left] > myArray[middle]) {
      swap(left, middle);
    }
    else if (myArray[middle] >= myArray[right]) {
      swap(middle, right);
    }
  }
  return middle;
}
int QS::partition(int left, int right, int pivotIndex) {
  if (arrayIsEmpty || left >= right || left < 0 || right >= currentIndex) {
    return -1;
  }
  if (pivotIndex < left || pivotIndex > right) {
    return -1;
  }
  int up = left + 1;
  int down = right;
  swap(left, pivotIndex);
  // cout << "left is " << myArray[left] << " value at pivot is " << myArray[pivotIndex] << endl;
  while (up < down) {
    // cout << "01" << endl;
    while (myArray[left] < myArray[down] && down > left) {
      // cout << "02" << endl;
      down--;
    }
    while (myArray[left] >= myArray[up] && up < right) {
      // cout << "03" << endl;
      up++;
    }
    if (up < down) {
      // cout << "swapping" << endl;
      swap(up, down);
      up = left + 1;
      down = right;
    }
    //cout << "breaking" << endl;
    //break;
  }
  swap(left, down);
  return down;
}
string QS::getArray() const {
  stringstream printArray;
  if (arrayIsEmpty) {
      printArray << "";
      return printArray.str();
  }
  for (int i = 0; i < currentIndex; i++) {
    if (i == currentIndex - 1) {
      printArray << myArray[i];
      break;
    }
    printArray << myArray[i] << ",";
  }
  return printArray.str();
}
int QS::getSize() const {
  if (arrayIsEmpty) {
    return 0;
  }
  return currentIndex;
}
bool QS::addToArray(int value) {
  if (currentIndex == maxCapacity) {
    return false;
  }
  myArray[currentIndex] = value;
  currentIndex++;
  arrayIsEmpty = false;
  return true;
}
bool QS::createArray(int capacity) {
  delete [] myArray;
  myArray = new int[capacity];
  maxCapacity = capacity;
  currentIndex = 0;
  arrayIsEmpty = true;
  return true;
}
void QS::clear() {
  delete [] myArray;
  myArray = NULL;
  currentIndex = 0;
  arrayIsEmpty = true;
}
