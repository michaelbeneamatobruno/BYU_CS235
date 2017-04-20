#include "Deck.h"

using namespace std;

  Deck::Deck(){}
  Deck::~Deck(){}

  void Deck::ClearDeck()
  {
    myDeck.clear();
  }
  string Deck::ComputerDrawCard()
  {
    string cardDrawn;
    srand(time(NULL));
    int index = 0;
    index = rand() % DeckSize();
    index = (DeckSize() - 1) - index;
    cardDrawn = getAt(index);
    removeFromBeginning(cardDrawn);
    return cardDrawn;
  }
  string Deck::PlayerDrawCard()
  {
    string cardDrawn;
    srand(time(NULL));
    cardDrawn = getAt(rand() % DeckSize());
    removeFromBeginning(cardDrawn);
    return cardDrawn;
  }
  void Deck::RemoveDuplicates()
  {
    string cardToCheck;
    int deckSize = 0;
    deckSize = DeckSize();

    while (deckSize > 0) {
      cardToCheck = getFront();
      popFront();
      if (IsDuplicate(cardToCheck)) {
        cout << cardToCheck << endl;
        removeFromBeginning(cardToCheck);
        deckSize -= 2;
        return;
      }
      else {
        pushBack(cardToCheck);
        deckSize--;
        return;
      }
    }
    return;


  }
  void Deck::ShuffleDeck()
  {
    srand(time(NULL));
    for (int i = 100; i > 0; i--) {
      pushAfter(getFront(), getAt(rand() % DeckSize()));
      popFront();
    }
  }
  bool Deck::IsEmpty()
  {
    if (myDeck.size() == 0) {
      return true;
    }
    return false;
  }
  void Deck::pushFront(string value)
  {
    myDeck.insertHead(value);
    return;
  }
  void Deck::popFront()
  {
    if (IsEmpty()) {
      return;
    }
    myDeck.remove(myDeck.at(0));
    return;
  }
  void Deck::pushBack(string value)
  {
    myDeck.insertTail(value);
    return;
  }
  void Deck::popBack()
  {
    if (IsEmpty()) {
      return;
    }
    myDeck.remove(myDeck.at(myDeck.size() - 1));
    return;
  }
  string Deck::getFront()
  {
    if (IsEmpty()) {
      return "Empty Deck";
    }
    return myDeck.at(0);
  }
  string Deck::getBack()
  {
    if (IsEmpty()) {
      return "Empty Deck";
    }
    return myDeck.at(myDeck.size() - 1);
  }
  string Deck::getAt(int index)
  {
    if (IsEmpty()) {
      return "Empty Deck";
    }
    return myDeck.at(index);
  }
  string Deck::getAtFromEnd(int index)
  {
    return myDeck.atFromEnd(index);
  }
  void Deck::removeFromBeginning(string value)
  {
    myDeck.remove(value);
    return;
  }
  void Deck::removeFromEnd(string value)
  {
    myDeck.removeFromEnd(value);
    return;
  }
  bool Deck::IsDuplicate(string value)
  {
    return myDeck.duplicateChecker(value);
  }
  void Deck::pushAfter(string insertValue, string value)
  {
    myDeck.insertAfter(insertValue, value);
    return;
  }
  int Deck::DeckSize()
  {
    return myDeck.size();
  }
  string Deck::toString()
  {
    return myDeck.printList();
  }
