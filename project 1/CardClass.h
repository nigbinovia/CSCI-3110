#include "CardType.h"

#ifndef CARDS_H
#define CARDS_H

class CardClass
{
  public:

//this default constructor creates a card class for the events a deck of cards will go through 
  CardClass();

// this function shuffles an instacne of a deck of cards 
  void ShuffleCard();

// this function deals an instance of a deck of cards 
  CardType DealCard();  

// this function returns how many cards are currently in the card deck 
  int GetSize(int count);

// this function returns if the card deck has remaining cards or not 
  bool IsEmpty(int count);
  

  private:

//a count variable is initalized and declared to count how many cards are remaining in the deck
  int count; 

//an CardType array is declared for a deck of cards to be implemented 
  CardType deck[52]; 
  
};

 #endif
