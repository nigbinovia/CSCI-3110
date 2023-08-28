#include "type.h"
#include <iomanip>

// the overloaded operators are defined in this file 

// the bool == operator compares the origins and destinations between two flightRec objects
bool flightRec::operator == (const flightRec & rhs) const
{
  return ((origin == rhs.origin) && (destination == rhs.destination));
}

// bool < operator compares the destinations between two flightRec objects
bool flightRec::operator < (const flightRec & rhs) const
{
  //if ((origin < rhs.origin) && destination < rhs.destination)
  if ( destination < rhs.destination)
    return true;
  return false;
}

//bool << operator prints out contents of a flightRec object 
ostream& operator << (ostream & os, const flightRec & f)
{
  os << left << setw(20) << f.destination << left << setw(12) << f.flightNum << left << setw(5) << f.price;
  
  return os;
}
