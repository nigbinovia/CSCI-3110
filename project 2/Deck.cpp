#include "Deck.h"
// this constructor creates a instance of a 
// deck of cards 
Deck::Deck()
{
// the top card of the deck is set to 52
  topCard = 52;
  
// for every elementof theDeck array
  for (int i = 0; i < 52; i++)
  {
    
// if i is from 0 - 12, the face value is assigned 
// with the CLUB suit type 
    if (i < 13)
    {
      theDeck[i] = Card(i + 2, CLUB);
    }

// if i is from 13 - 25, the face value is assigned 
// with the DIAMOND suit type 
    else if ((i >= 13) && (i < 26))
    {
      theDeck[i] = Card(i - 11, DIAMOND);
    }
      
// if i is from 26 - 38, the face value is assigned 
// with the HEART suit type 
      
    else if ((i >= 26) && (i < 39))
    {
      theDeck[i] = Card(i - 24, HEART);
    }
      
// if i is from 37 - 51, the face value is assigned 
// with the SPADE suit type 
    else 
    {
      theDeck[i] = Card(i - 37, SPADE);
    }
  }
}

// this function removes the top card 
// from theDeck and deals it to a player
Card Deck::dealCard()
{
// the temp variable is declared and used to 
// pick the current card to be returned 
  int temp;
  temp = 52 - topCard;
  topCard--;

  return theDeck[temp];
  
}

// this function shuffles the cards in a deck 
void Deck::shuffle()
{
// a card variable is declared 
  Card temp;

// for a cycle that continues for 100n times 
  for (int i = 0; i < 100; i++)
  {
// two random cards from the deck are assigned to the variables x and y
    int x = rand() % 52;
    int y = rand() % 52;

// using a temporary CardType variable, the two cards switch places 
    temp = theDeck[x];
    theDeck[x] = theDeck[y];
    theDeck[y] = temp;
    
    
  }
}

// this function returns true if there's no more 
// cards in the deck, otherwise it returns false 
bool Deck::isEmpty()
{
  if (topCard == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// overload << operator to display the deck
ostream& operator << (ostream& os, const Deck& rhs)
{
// for every card in the deck, each card is displayed 
  for (int i = 0; i < 52; i++)
  {
    os << rhs.theDeck[i] << endl;
  }
  return os;
}
