#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "Card.h"

using std::ostream;

class Deck
{
public:

    // default constructor
	Deck();

    // Remove the top card from the deck
    // and return it.
	Card dealCard();

    // Shuffle the cards on the deck
	void shuffle();

    // return true is no more cards on the deck,
    // otherwise return false
	bool isEmpty();

    //overload << operator to display the deck
  friend ostream& operator << (ostream& os, const Deck& rhs);

private:
    static const int Card_Num = 52; //Max # of cards in  a deck

	Card    theDeck[Card_Num];    // the array holding the cards
	int     topCard;              // the index of the top card on the deck
};

#endif
