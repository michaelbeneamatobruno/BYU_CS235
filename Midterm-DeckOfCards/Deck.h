#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;


class Deck
{
private:
  LinkedList<string> myDeck;

public:
  Deck();
  ~Deck();

  void ClearDeck();
  string ComputerDrawCard();
  string PlayerDrawCard();
  void RemoveDuplicates();
  void ShuffleDeck();
  bool IsEmpty();
  void pushFront(string value);
  void popFront();
  void pushBack(string value);
  void popBack();
  string getFront();
  string getBack();
  string getAt(int index);
  string getAtFromEnd(int index);
  void removeFromBeginning(string value);
  void removeFromEnd(string value);
  bool IsDuplicate(string value);
  void pushAfter(string insertValue, string value);
  int DeckSize();
  string toString();

};
