#include <iostream>
#include <sstream>
#include <fstream>
#include "Station.h"
#include "LinkedList.h"

using namespace std;

void cinError() {
  cin.clear();
  cin.ignore(1000, '\n');
  cout << "Error: Not a valid int" << endl;
}

void AddToStructs(int structChoice, Station &myStation) {
  switch (structChoice) {
    case 1:
      // cout << "Here3" << endl;
      if (myStation.addToStack()) {
        cout << "Current car has been added to the beginning of the stack" << endl;
        // cout << "New size of stack is: " << myStation.showSizeOfStack() << endl;
        break;
      }
      cout << "Car was not added to stack" << endl;
      break;
    case 2:
      if (myStation.addToQueue()) {
        cout << "Current car has been added to the beginning of the queue" << endl;
        break;
      }
      cout << "car was not added to queue" << endl;
      break;
    case 3:
      if (myStation.addToDequeRight()) {
        cout << "Current car has been added to the beginning of the deque" << endl;
        break;
      }
      cout << "Car was not added to deque" << endl;
      break;
    case 4:
      if (myStation.addToDequeLeft()) {
        cout << "Current car has been added to the end of the deque" << endl;
        break;
      }
      cout << "Car was not added to deque" << endl;
      break;
    case 5:
      if (myStation.addToIRDequeLeft()) {
        cout << "Current car has been added to the end of the IRdeque" << endl;
        break;
      }
      cout << "Car was not added to deque" << endl;
      break;
    case 6:
      if (myStation.addToORDequeRight()) {
        cout << "Current car has been added to the end of the ORdeque" << endl;
        break;
      }
      cout << "Car was not added to deque" << endl;
      break;
    case 7:
      if (myStation.addToORDequeLeft()) {
        cout << "Current car has been added to the end of the ORdeque" << endl;
        break;
      }
      cout << "Car was not added to deque" << endl;
      break;
    default:
      cout << "Invalid selection" << endl;
      break;
  }
}

void RemoveFromStructAdd2Station(int carID, Station &myStation) {
  // cout << "Here1: " << carID << endl;
  if (myStation.showTopOfStack() == carID) {
    // cout << "Here0" << endl;
    myStation.removeFromStack();
    cout << carID << " was taken from stack and added to station" << endl;
  }
  else if (myStation.showTopOfQueue() == carID) {
    // cout << "top of queue" << myStation.showTopOfQueue() << endl;
    myStation.removeFromQueue();
    cout << carID << " was taken from queue and added to station" << endl;
  }
  else if (myStation.showTopOfDequeRight() == carID) {
    myStation.removeFromDequeRight();
    cout << carID << " was taken from deque head and added to station" << endl;
  }
  else if (myStation.showTopOfDequeLeft() == carID) {
    myStation.removeFromDequeLeft();
    cout << carID << " was taken from deque tail and added to station" << endl;
  }
  else if (myStation.showTopOfORDequeLeft() == carID) {
    myStation.removeFromORDequeLeft();
    cout << carID << " was taken from IRDeque and added to station" << endl;
  }
  else if (myStation.showTopOfIRDequeRight() == carID) {
    myStation.removeFromIRDequeRight();
    cout << carID << " was taken from ORDeque head and added to station" << endl;
  }
  else if (myStation.showTopOfIRDequeLeft() == carID) {
    myStation.removeFromIRDequeLeft();
    cout << carID << " was taken from IRDeque and added to station" << endl;
  }
  else {
    cout << "That car is not in any data structures accesible location" << endl;
  }
}

void ShowAllSizes(Station &myStation) {
  //stack
  if (myStation.showTopOfStack() == -1) {
    cout << endl << "Stack: Empty" << endl;
  }
  else {
    cout << endl << "Stack: " << myStation.showTopOfStack() << endl;  
  }
  //queue
  if (myStation.showTopOfQueue() == -1) {
    cout << "Queue: Empty" << endl;
  }
  else {
    cout << "Queue: " << myStation.showTopOfQueue() << endl;  
  }
  //deque
  if (myStation.showTopOfDequeLeft() == -1) {
    cout << "Deque: Empty" << endl;
  }
  else if (myStation.showTopOfDequeLeft() == myStation.showTopOfDequeRight()) {
    cout << "Deque: " << myStation.showTopOfDequeRight() << endl;
  }
  else {
    cout << "Deque: " << myStation.showTopOfDequeLeft() << ", " << myStation.showTopOfDequeRight() << endl;
  }
  //IRdeque
  if (myStation.showTopOfIRDequeLeft() == -1) {
    cout << "IRDeque: Empty" << endl;
  }
  else if (myStation.showTopOfIRDequeLeft() == myStation.showTopOfIRDequeRight()) {
    cout << "IRDeque: " << myStation.showTopOfIRDequeRight() << endl;
  }
  else {
    cout << "IRDeque: " << myStation.showTopOfIRDequeLeft() << ", " << myStation.showTopOfIRDequeRight() << endl;
  }
  //ORDeque
  if (myStation.showTopOfORDequeLeft() == -1) {
    cout << "ORDeque: Empty" << endl;
  }
  else {
    cout << "ORdeque: " << myStation.showTopOfORDequeLeft() << endl;
  }
  
  // cout << "Stack: " << myStation.toStringStack() << endl;
  
  // cout << "poop" << endl;
  
  
  if (myStation.showCurrentCar() == -1) {
    cout << "Station: Empty" << endl;
  }
  else {
    // cout << "entered into else" << endl;
    cout << "Station: " << myStation.showCurrentCar() << endl;
  }
}

int main() {

  int userInput = 0;
  int carID = -1;
  Station myStation;
  string name;
  int choice_num = 0;

  string choices[] =
  {
    "Add a car to the station",
    "Remove a car from the station",
    "Add a car from the station to a storage facility",
    "Remove a car from a storage facility and add it to the station",
    "Display the cars currently accessible in the station and storage facilities.",
    "Quit."
  };
  const int NUM_CHOICES = 6;

  // Perform all operations selected by user.
  while (choice_num != NUM_CHOICES) {
    // Select the next operation.
    cout << endl << "Select an operation" << endl;
    for (int i = 0; i < NUM_CHOICES; i++) {
      cout << i + 1 << ": " << choices[i] << endl;
    }
    cout << endl << "Enter your option: ";
    cin >> choice_num;
    if (cin.fail()) {
      cinError();
      continue;
    }
    switch (choice_num) {
    case 1:
      cout << "Enter new car ID: ";
      cin >> carID;
      if (cin.fail()) {
        cinError();
        continue;
      }
      if (myStation.addToStation(carID)) {
        cout << "Car has been added to station" << endl;
        break;
      }
      cout << "Car was not added" << endl;
      break;
    case 2:
      if (myStation.removeFromStation()) {
        cout << "Car has been removed from station" << endl;
        break;
      }
      cout << "Car was not removed" << endl;
      break;
    case 3:
    {
      string structures[] =
      {
        "Stack",
        "Queue",
        "Deque Right",
        "Deque Left",
        "IRDeque",
        "ORDeque Right",
        "ORDeque Left"
      };
      cout << endl << "Select where you would like to insert" << endl;
      for (int i = 0; i < 7; i++) {
        cout << i + 1 << ": " << structures[i] << endl;
      }
      cout << endl << "Enter your choice: ";
      int structChoice = 0;
      cin >> structChoice;
      if (cin.fail()) {
        cinError();
        continue;
      }
      cout << endl;
      AddToStructs(structChoice, myStation);
    }
      break;
    case 4:
      cout << endl << "Enter the Car you would like to take from a structure and add to the station: ";
      cin >> carID;
      if (cin.fail()) {
        cinError();
        continue;
      }
      if (carID < 0) {
        cout << "Error: Invalid number" << endl;
        continue;
      }
      RemoveFromStructAdd2Station(carID, myStation);
      break;
    case 5:
      ShowAllSizes(myStation);
      break;
    case 6:
      cout << endl << "CHOO CHOO CIAO" << endl;
      break;
    default:
      cout << "Invalid selection" << endl;
      break;
    }
  } // End while.

    return 0;

}
