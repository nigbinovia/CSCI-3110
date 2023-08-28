#include "Card.h"
#include <iomanip>

// default constructor 
Card::Card() 
{  
}

// this value constructor creates an instance of a 
// card object with a face value and a suit type
Card::Card (int faceValue, cardType atype) : faceValue(faceValue), suit(atype)
{
}

// overloaded << operator
ostream& operator << (ostream & os, const Card & rhs)
{

//an int variable to defined to caluclate the point 
// value of a card
  int p = rhs.getPointValue();

// if the enum type is CLUB, CLUB is printed 
  if (rhs.suit == CLUB)
    os << "CLUB";

// if the enum type is DIAMOND, DIAMOND is printed 
  else if (rhs.suit == DIAMOND)
    os << "DIAMOND";

// if the enum type is HEART, HEART is printed 
  else if (rhs.suit == HEART)
    os << "HEART";

// // if the enum type is SPADE, SPADE is printed 
  else
    os << "SPADE";
  
  os << "-";
  
  //os << rhs.faceValue; 
  if (rhs.faceValue < 11)
    os << rhs.faceValue;
  else if (rhs.faceValue == 11)
    os << "Jack";
  else if (rhs.faceValue == 12)
    os << "Queen";
  else if (rhs.faceValue == 13)
    os << "King";
  else
    os << "Ace";

  os << " " << p << " points";
  
  return os;
}

// overloaded < operator 
bool Card::operator < (const Card& rhs) const
{
// if the face value is smaller than the rhs
// true is returned, otherwise false is returned 
  if (faceValue < rhs.faceValue)
    return true;
  return false;
}

// overloaded > operator
bool Card::operator > (const Card & rhs) const
{
// if the face value is larger than the rhs
// true is returned, otherwise false is returned 
  if (faceValue > rhs.faceValue)
    return true;
  return false;
}

// overloaded == operator
bool Card::operator == (const Card & rhs) const
{
// if the face value is equal to the rhs
// true is returned, otherwise false is returned 
  if (faceValue == rhs.faceValue)
    return true;
  return false;
}

// returns the point value of a card object
int Card::getPointValue() const
{
// if the face value is less than or equal to 10,
// the point value is the same as the face value 
  if (faceValue <= 10)
    return faceValue; 

// if the face value is between 11 and 13, the point 
// value is set to 10 points
  else if ((faceValue >= 11) && (faceValue <= 13))
    return 10;
// if the face value is 14, the point value is set to 15 
  else 
    return 15;
} 
