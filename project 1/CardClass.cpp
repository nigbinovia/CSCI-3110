#include "CardClass.h"
#include <cstdlib>
#include <iostream>
using namespace std;

// constant is declared and initalized for the size of the deck
const int SIZE = 52;

CardClass::CardClass() 
{
  // the array and variables are declared and initalized
  count = SIZE;

  for (int i = 0; i < 52; i++) {
    if (i < 13) {
      deck[i].suit = DIAMOND;
      deck[i].value = (i + 2);
      deck[i].points = 0;
      if (i == 10) {
        deck[i].points = -100;
      }
    }

    else if ((i >= 13) && (i < 26)) {
      deck[i].suit = CLUB;
      deck[i].value = (i - 12);
      deck[i].points = 0;
    }

    else if ((i >= 26) && (i < 39)) {
      deck[i].suit = HEART;
      deck[i].value = (i - 25);

      if ((i >= 26) && (i < 35)) {
        deck[i].points = 5;
      } else {
        deck[i].points = 10;
      }
    }

    else {
      deck[i].suit = SPADE;
      deck[i].value = (i - 38);
      deck[i].points = 0;

      if (i == 50) {
        deck[i].points = 100;
      }
    }
  }
}

void CardClass::ShuffleCard() 
{

  CardType temp;

  for (int i = 0; i < 100; i++) {

  // two random cards from the deck are assigned to the variables x and y 
    int x = rand() % 52;
    int y = rand() % 52;

// using a temporary CardType variable, the two cards switch places 
    temp = deck[x];
    deck[x] = deck[y];
    deck[y] = temp;

    // this cycle continues for a 100 times 
  }


}

CardType CardClass::DealCard() 
{

  int top;
  CardType temp;

// the top of the deck is identified and the count is redetermined 
// after a card is removed 
  top = 52 - count;
  count = count - 1;

// the top card is returned to be put into a certain pile for a player 
  return deck[top];
}

int CardClass::GetSize(int count) 
{ 
  // the current number of cards in the deck are returned 
  return count; 
}

bool CardClass::IsEmpty(int count) 
{
  // if there are no cards left in the deck, true is returned 
  if (count == 0) 
  {
    return true;
  } 

  // otherwise false is returend
  else 
  {
    return false;
  }
}
