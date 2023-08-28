/*
PROGRAMMER:       	Naomi Igbinovia
Program Description:
This program implments the preparation routines used in a card game played
among four players. 
Inputs: a CardType Struct, a CardClass class, a count and
cardType array data members, 4 enum variables, and a few functions to shuffle,
deal, sort and print the cards
Outputs: 4 hands for 4 players organized by suit printed, and if the 2 of
clubs is found, a message stating such is printed too 
*/

#include "CardClass.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;

// the functions are declared
void SortCards(CardType Player[]);
void PrintCards(CardType Player[],int);
int LinearSearch(CardType Player[], int);

int main() {
  // variables are declared and initlaized
  int count = 52;
  int numPlayer = 0;

  // a CardClass object is created
  CardClass PlayingDeck;

  // each player is defined with a 1D array
  CardType Player1[13];
  CardType Player2[13];
  CardType Player3[13];
  CardType Player4[13];

  srand(time(0));

  // the ShuffleCard function is called for use
  PlayingDeck.ShuffleCard();

  // the deck of cards is dealt among the 4 players using the DealCard function
  for (int i = 0; i < 13; i++) {
    
    Player1[i] = PlayingDeck.DealCard();  
    Player2[i] = PlayingDeck.DealCard();
    Player3[i] = PlayingDeck.DealCard();
    Player4[i] = PlayingDeck.DealCard();
  }

  SortCards(Player1);
  SortCards(Player2);
  SortCards(Player3);
  SortCards(Player4);
  
  cout << "PLAYER 1" << endl;
  PrintCards(Player1,1);
 
  cout << "PLAYER 2" << endl;
  PrintCards(Player2,2);
  
  cout << "PLAYER 3" << endl;
  PrintCards(Player3,3);
 
  cout << "PLAYER 4" << endl;
  PrintCards(Player4,4);
  
  
}

// this function sorts a player's cards by suit 
void SortCards(CardType Player[]) {
  //the sorted variable  indicates whether additional comparison passes are needed
  bool sorted = false; 

  // this varibale stored the index of the last item in the remaining part of the array
  int last = 13 - 1; 

  CardType tmp;

  while (!sorted) {
    // assuming the remaining array is sorted.
    sorted = true;
    for (int i = 0; i < last; i++) {
      if (Player[i].suit > Player[i + 1].suit) {
        // swap the two records
        tmp = Player[i];
        Player[i] = Player[i + 1];
        Player[i + 1] = tmp;

        // the remaining array is not sorted, need at least another pass
        // of pairwise comparison
        sorted = false;
      }
    }

    last--;
  }

  return;
}


// the PrintCard function displays the cards in a player's hand by suit, value,
// and points.

void PrintCards(CardType Player[], int numPlayer) {
// a check variable is defined to be used to check for the 2 of Clubs. 
  int check = 0;

// the title banner is printed 
  cout << left << setw(10) << "SUIT" << left << setw(10) << "VALUE" << left << setw(10) << "POINTS" << endl;
  for (int i = 0; i < 13; i++)
  {
// the cards of the diamond suit are printed 
    if (Player[i].suit == 0)
    {
// the value 14 is changed to A and the card is printed 
      if (Player[i].value == 14)
      cout << left << setw(10) << "Diamond" << left << setw(10) << "A" << left << setw(10) << Player[i].points << endl;
// the value 11 is changed to J and the card is printed 
      else if (Player[i].value == 11)
      cout << left << setw(10) << "Diamond" << left << setw(10) << "J" << left << setw(10) << Player[i].points << endl;
// the value 12 is changed to Q and the card is printed 
      else if (Player[i].value == 12)
      cout << left << setw(10) << "Diamond" << left << setw(10) << "Q" << left << setw(10) << Player[i].points << endl;
// the value 13 is changed to K and the card is printed 
      else if (Player[i].value == 13)
      cout << left << setw(10) << "Diamond" << left << setw(10) << "K" << left << setw(10) << Player[i].points << endl;
// the remaining cards are printed 
      else
      cout << left << setw(10) << "Diamond" << left << setw(10) << Player[i].value << left << setw(10) << Player[i].points << endl;
    }

// the cards of the club suit are printed  
    else if (Player[i].suit == 1)
    {
// if the 2 of clubs is found the check variable is notified to 
// be printed at the end of the loop
      if (Player[i].value == 2)
      {
        check = 1;
      }
// the value 14 is changed to A and the card is printed 
      else if (Player[i].value == 14)
      cout << left << setw(10) << "Club" << left << setw(10) << "A" << left << setw(10) << Player[i].points << endl;
// the value 11 is changed to J and the card is printed 
      else if (Player[i].value == 11)
      cout << left << setw(10) << "Club" << left << setw(10) << "J" << left << setw(10) << Player[i].points << endl;
// the value 12 is changed to Q and the card is printed 
      else if (Player[i].value == 12)
      cout << left << setw(10) << "Club" << left << setw(10) << "Q" << left << setw(10) << Player[i].points << endl;
// the value 13 is changed to K and the card is printed 
      else if (Player[i].value == 13)
      cout << left << setw(10) << "Club" << left << setw(10) << "K" << left << setw(10) << Player[i].points << endl;
      else 
// the remaining cards are printed 
      cout << left << setw(10) << "Club" << left << setw(10) << Player[i].value << left << setw(10) << Player[i].points << endl;
  
    }

// the cards of the heart suit are printed  
    else if (Player[i].suit == 2)
    {
// the value 14 is changed to A and the card is printed 
      if (Player[i].value == 14)
      cout << left << setw(10) << "Heart" << left << setw(10) << "A" << left << setw(10) << Player[i].points << endl;
// the value 11 is changed to J and the card is printed 
      else if (Player[i].value == 11)
      cout << left << setw(10) << "Heart" << left << setw(10) << "J" << left << setw(10) << Player[i].points << endl;
// the value 12 is changed to Q and the card is printed 
      else if (Player[i].value == 12)
      cout << left << setw(10) << "Heart" << left << setw(10) << "Q" << left << setw(10) << Player[i].points << endl;
// the value 13 is changed to K and the card is printed 
      else if (Player[i].value == 13)
      cout << left << setw(10) << "Heart" << left << setw(10) << "K" << left << setw(10) << Player[i].points << endl;
      else
// the remaining cards are printed 
      cout << left << setw(10) << "Heart" << left << setw(10) << Player[i].value << left << setw(10) << Player[i].points << endl;
    }

    
// the cards of the spade suit are printed  
    else if (Player[i].suit == 3)
    {
// the value 14 is changed to A and the card is printed 
      if (Player[i].value == 14)
      cout << left << setw(10) << "Spade" << left << setw(10) << "A" << left << setw(10) << Player[i].points << endl;
// the value 11 is changed to J and the card is printed 
      else if (Player[i].value == 11)
      cout << left << setw(10) << "Spade"  << left << setw(10) << "J" << left << setw(10) << Player[i].points << endl;
// the value 12 is changed to Q and the card is printed 
      else if (Player[i].value == 12)
      cout << left << setw(10) << "Spade"  << left << setw(10) << "Q" << left << setw(10) << Player[i].points << endl;
// the value 13 is changed to K and the card is printed 
      else if (Player[i].value == 1)
      cout << left << setw(10) << "Spade"  << left << setw(10) << "K" << left << setw(10) << Player[i].points << endl;
      else
// the remaining cards are printed 
      cout << left << setw(10) << "Spade"  << left << setw(10) << Player[i].value << left << setw(10) << Player[i].points << endl;
    }   
  }
  
// if the check variable is set to one by the end of the loop, 
// the statement that the 2 of clubs was found is printed 
  if (check == 1)
    {
      cout << endl;
      cout << "Player " << numPlayer << " has the 2 of Clubs." << endl;
    }
  
  cout << endl;
}
