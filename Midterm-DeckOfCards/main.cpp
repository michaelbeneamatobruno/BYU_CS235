#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include "Deck.h"
#include <vector>

using namespace std;

void CreateDeck(string fileName, Deck &myDeck) {
  myDeck.ClearDeck();
  ifstream myFile(fileName);
  string line;
  while (myFile.good()) {
    getline(myFile, line);
    if (line.length() == 0) {
      continue;
    }
    if (isspace(line.at(0))) {
      continue;
    }
    myDeck.pushFront(line);
    myDeck.pushFront(line);
  }
  if (myDeck.IsEmpty()) {
    cout << "The deck was not created." << endl;
  }
}

void ShuffleDeck(Deck someDeck) {
  someDeck.ShuffleDeck();
}

void ComputersTurn(Deck &computerHand, Deck &playerHand, Deck &myDeck, int &computerScore) {
  string computerCard;
  cout << "It is the computer's turn." << endl;
  srand(time(NULL));
  computerCard = computerHand.getAt(rand() % computerHand.DeckSize());
  cout << "the computer guesses: " << computerCard;
  cout << endl;
  if (playerHand.IsDuplicate(computerCard)) {
    cout << "It's a match!!!" << endl;
    computerHand.removeFromEnd(computerCard);
    playerHand.removeFromBeginning(computerCard);
    computerScore++;
    return;
  }
  cout << "Go Fish" << endl;
  if (myDeck.DeckSize() != 0) {
    computerCard = myDeck.ComputerDrawCard();
    if (computerHand.IsDuplicate(computerCard)) {
      computerHand.removeFromEnd(computerCard);
      cout << "The computer picked up " << computerCard << ", it already had this card in it's hand. The card has been discarded, the computer earns 1 point." << endl;
      computerScore++;
      return;
    }
    computerHand.pushBack(computerCard);
    return;
  }
  cout << "The deck is empty, no cards were drawn. The game continues until one player empties his/her hand." << endl;
  return;
}

void IntelligentComputer(Deck &computerHand, Deck &playerHand, Deck &myDeck, int &computerScore, string lastGuess) {
  string computerCard;
  // cout << "This is the IntelligentComputer, it keeps track of all of the player's guesses and if it draws a card that has already been guessed it will guess that card"
  cout << "It is the computer's turn." << endl;
  cout << "The computer is checking if it has picked up the last card the player guessed..." << endl;
  if (computerHand.IsDuplicate(lastGuess)) {
    computerCard = lastGuess;
  }
  else {
    srand(time(NULL));
    computerCard = computerHand.getAt(rand() % computerHand.DeckSize());
  }
  cout << "the computer guesses: " << computerCard;
  cout << endl;
  if (playerHand.IsDuplicate(computerCard)) {
    cout << "It's a match!!!" << endl;
    computerHand.removeFromEnd(computerCard);
    playerHand.removeFromBeginning(computerCard);
    computerScore++;
    return;
  }
  cout << "Go Fish" << endl;
  if (myDeck.DeckSize() != 0) {
    computerCard = myDeck.ComputerDrawCard();
    if (computerHand.IsDuplicate(computerCard)) {
      computerHand.removeFromEnd(computerCard);
      cout << "The computer picked up " << computerCard << ", it already had this card in it's hand. The card has been discarded, the computer earns 1 point." << endl;
      computerScore++;
      return;
    }
    computerHand.pushBack(computerCard);
    return;
  }
  cout << "The deck is empty, no cards were drawn. The game continues until one player empties his/her hand." << endl;
  return;
}

void cinError() {
  cin.clear();
  cin.ignore(1000, '\n');
  cout << "Error: invalid input" << endl;
}

void displayPlayerHand(Deck &someDeck) {
  if (someDeck.DeckSize() == 0) {
    cout << "Player: Empty" << endl;
    return;
  }
  cout << "Player: " << someDeck.toString() << endl;
  return;
}

void displayComputerHand(Deck &someDeck) {
  if (someDeck.DeckSize() == 0) {
    cout << "Computer: Empty" << endl;
    return;
  }
  cout << "Computer: " << someDeck.toString() << endl;
  return;
}

void displayDeck(Deck &someDeck) {
  cout << "Deck:" << endl;
  if (someDeck.DeckSize() == 0) {
    cout << "Empty" << endl;
    return;
  }
  for (int i = 0; i < someDeck.DeckSize(); i++) {
    cout << someDeck.getAt(i) << endl;
  }
  // for (int i = 0; i < someDeck.DeckSize(); i++) {
  //   cout << someDeck.getAtFromEnd(i) << endl;
  // }
  // for (int i = 0; i < someDeck.DeckSize(); i++) {
  //   cout << someDeck.getAtFromEnd(i) << endl;
  // }
}

void DealCards(Deck &myDeck, Deck &playerHand, Deck &computerHand, int handSize) {
  // cout << "DEALCARDS" << endl;
  for (int i = 0; i < handSize; i++) {
    if (myDeck.DeckSize() == 0) {
      cout << "There are not enough cards, all cards in the deck have been dealt." << endl;
      return;
    }
    playerHand.pushBack(myDeck.PlayerDrawCard());
    // cout << endl << "DEALCARDS::Player's Hand: " << playerHand.toString() << endl;
    if (myDeck.DeckSize() == 0) {
      cout << "There are not enough cards, all cards in the deck have been dealt." << endl;
      return;
    }
    computerHand.pushBack(myDeck.ComputerDrawCard());
    // cout << endl << "DEALCARDS::Computer's Hand: " << computerHand.toString() << endl;
  }
  return;
}

void PlayGame(int &gameSelection, Deck &playerHand, Deck &computerHand, Deck &myDeck, int &computerScore, int &playerScore) {
  switch(gameSelection) {
    case 0: //Intuitive computer
    {
      string card;
      while (!playerHand.IsDuplicate(card)) {
        string lastGuess;
        cout << "It is your turn." << endl;
        cout << "Your hand has the following cards." << endl;
        displayPlayerHand(playerHand);
        cout << "Please enter the card you would like to guess(name number): ";
        getline(cin, card);
        cout << card << endl;
        if (cin.fail()) {
          cinError();
          cout << "please try again" << endl;
          continue;
        }
        if (!playerHand.IsDuplicate(card)) {
          cout << endl << "That card is not in your deck, please try again." << endl;
          continue;
        }
        if (computerHand.IsDuplicate(card)) {
          cout << "It's a match!!!" << endl;
          computerHand.removeFromEnd(card);
          playerHand.removeFromBeginning(card);
          playerScore++;
          IntelligentComputer(computerHand, playerHand, myDeck, computerScore, lastGuess);
          break;
        }
        cout << "Go Fish" << endl;
        lastGuess = card;
        card = myDeck.PlayerDrawCard();
        if (playerHand.IsDuplicate(card)) {
          playerHand.removeFromBeginning(card);
          playerScore++;
          IntelligentComputer(computerHand, playerHand, myDeck, computerScore, lastGuess);
          break;
        }
        playerHand.pushBack(card);
        IntelligentComputer(computerHand, playerHand, myDeck, computerScore, lastGuess);
        break;
      }
      break;
    }
    case 1:
    {
      string card;
      while (!playerHand.IsDuplicate(card)) {
        string computerCard;
        cout << "It is your turn." << endl;
        cout << "Your hand has the following cards." << endl;
        displayPlayerHand(playerHand);
        cout << "Please enter the card you would like to guess(name number): ";
        getline(cin, card);
        cout << card << endl;
        if (cin.fail()) {
          cinError();
          cout << "please try again" << endl;
          continue;
        }
        if (!playerHand.IsDuplicate(card)) {
          cout << endl << "That card is not in your deck, please try again." << endl;
          continue;
        }
        if (computerHand.IsDuplicate(card)) {
          cout << "It's a match!!!" << endl;
          computerHand.removeFromEnd(card);
          playerHand.removeFromBeginning(card);
          playerScore++;
          if (playerHand.DeckSize() == 0 || computerHand.DeckSize() == 0) {
            break;
          }
          ComputersTurn(computerHand, playerHand, myDeck, computerScore);
          break;
        }
        cout << "Go Fish" << endl;
        if (myDeck.DeckSize() != 0) {
          card = myDeck.PlayerDrawCard();
          if (playerHand.IsDuplicate(card)) {
            playerHand.removeFromBeginning(card);
            cout << "you picked up " << card << ", it is already in your deck. It has been removed and you earn 1 point." << endl;
            playerScore++;
            if (playerHand.DeckSize() == 0) {
              break;
            }
            ComputersTurn(computerHand, playerHand, myDeck, computerScore);
            break;
          }
          playerHand.pushBack(card);
          cout << "you picked up " << card <<", it has been added to your hand." << endl;
          ComputersTurn(computerHand, playerHand, myDeck, computerScore);
          break;
        }
        cout << "The deck is empty, no cards were drawn. The game continues until one player empties his/her hand." << endl;
        ComputersTurn(computerHand, playerHand, myDeck, computerScore);
        break;
      }
      break;
    }
    case 2:
      if (myDeck.DeckSize() == 0) {
        cout << "Cannot shuffle an empty Deck" << endl;
        break;
      }
      cout << "Shuffling Deck..." << endl;
      myDeck.ShuffleDeck();
      break;
    case 3:
      displayDeck(myDeck);
      break;
    case 4:
      displayComputerHand(computerHand);
      break;
    case 5:
      cout << "You gave up." << endl;
      break;
    default:
      cout << "Invalid Selection" << endl;
      break;
  }
}

void CheckWinner(int playerScore, int computerScore) {
  if (computerScore > playerScore) {
    cout << "Computer has won, better luck next time." << endl;
  }
  if (playerScore > computerScore) {
    cout << "YOU WIN!" << endl;
  }
  if (playerScore == computerScore) {
    cout << "It's a tie." << endl;
  }
}

int main() {
  int gameSelection = 0;
  const int NUM_GAME_CHOICES = 6;
  int choice = 0;
  const int NUM_CHOICES = 4;
  int initalHandSize = 0;
  string fileName;
  Deck myDeck;
  Deck playerHand;
  Deck computerHand;
  Deck playerGuesses;

  string choices[] =
  {
    "Create Deck",
    "Display Deck",
    "Play",
    "Quit"
  };

  while (choice != NUM_CHOICES) {
    cout << "Menu Options:" << endl << endl;
    for (int i = 0; i < NUM_CHOICES; i++) {
      cout << i + 1 << ": " << choices[i] << endl;
    }
    cout << endl << "Select an option: ";
    cin >> choice;
    cin.ignore();
    cout << endl;
    if (cin.fail()) {
      cinError();
      continue;
    }
    switch (choice) {
      case 1:
      {
        cout << "Enter a file name: ";
        cin >> fileName;
        cin.ignore();
        cout << endl;
        if (cin.fail()) {
          cinError();
          continue;
        }
        CreateDeck(fileName, myDeck);
        break;
      }
      case 2:
      {
        displayDeck(myDeck);
        break;
      }
      case 3:
      {
        int computerScore = 0;
        int playerScore = 0;
        if (myDeck.DeckSize() == 0) {
          cout << "Cannot play, the deck is empty" << endl;
          break;
        }
        cout << "Shuffling Deck..." << endl;
        myDeck.ShuffleDeck();
        cout << "Enter an Initial Hand Size: ";
        cin >> initalHandSize;
        cin.ignore();
        if (cin.fail()) {
          cinError();
          continue;
        }
        cout << "Dealing Cards..." << endl;
        DealCards(myDeck, playerHand, computerHand, initalHandSize);
        cout << "Removing duplicates" << endl;
        playerHand.RemoveDuplicates();
        computerHand.RemoveDuplicates();
        // if (playerHand.DeckSize() == 0 || computerHand.DeckSize() == 0) {
        //   cout << "checking for duplicates has emptied one of the hands, the game will automatically terminate." << endl;
        //   break;
        // }
        gameSelection = 0;
        while (gameSelection != NUM_GAME_CHOICES - 1) {
          if ((playerHand.DeckSize() == 0) && (computerHand.DeckSize() == 0)) {
            playerScore += 3;
            computerScore += 3;
            cout << "Both players are out of cards, game has ended." << endl;
            CheckWinner(playerScore, computerScore);
            break;
          }
          if (playerHand.DeckSize() == 0) {
            playerScore +=3;
            cout << "Player is out of cards, game has ended" << endl;
            CheckWinner(playerScore, computerScore);
            break;
          }
          if (computerHand.DeckSize() == 0) {
            computerScore += 3;
            cout << "computer is out of cards, game has ended" << endl;
            CheckWinner(playerScore, computerScore);
            break;
          }
          string gameChoices[] =
          {
            "Intelligent Computer Guess",
            "Make Guess",
            "Shuffle Deck",
            "Display Deck",
            "Display Computer Hand",
            "Give Up"
          };
          cout << endl << "Game Options:" << endl << endl;
          for (int i = 0; i < NUM_GAME_CHOICES; i++) {
            cout << i << ": " << gameChoices[i] << endl;
          }
          cout << endl << "Select an option: ";
          cin >> gameSelection;
          cin.ignore();
          cout << endl;
          if (cin.fail()) {
            cinError();
            continue;
          }
          PlayGame(gameSelection, playerHand, computerHand, myDeck, computerScore, playerScore);
        }
        playerHand.ClearDeck();
        computerHand.ClearDeck();
        myDeck.ClearDeck();
        cout << "The Deck and hands have been cleared." << endl;
        break;
      }
      case 4:
      {
        cout << "GOODBYE" << endl;
        break;
      }
      default:
      {
        cout << "Invalid choice" << endl;
        break;
      }
    }
  }

  return 0;

}
