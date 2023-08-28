#include <iostream>
#include <iomanip>
#include <cassert>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

#include "type.h"
#include "flightMap.h"

// implement the methods of the flightMap class here

//the default constructor sets cityNum to 0 for a flightMapClass object
FlightMapClass::FlightMapClass()
{
  cityNum = 0;
}

// the copy constructor sets the cityNum, aVector, and adjList variables of FlightMapClass object 2 to be same as FlightMapClass object 1
FlightMapClass::FlightMapClass(const FlightMapClass & rhs) 
{
  cityNum = rhs.cityNum;
  aVector = rhs.aVector;
  adjList = rhs.adjList;
}

// the deconstructor releases all the memory stored in the adjList variable
FlightMapClass::~FlightMapClass() 
{
  delete [] adjList;
}


// this function reads in cities from a data file into a vector and are sorted in ascending order. 
void FlightMapClass::ReadCities(ifstream & myIn) 
{
// the function variables are declared and initalized
  int count = 0;
  string city; 

// the first line of the cities.dat file is the total number of cities listed in the file, so that value is stored in count
  myIn >> count;

// while there are still cities to be read into the temporary city variable
  while (myIn >> city) 
  {
// the current city is added to the end of the vector 
    aVector.push_back(city); 
  }
// the sort function is called to sort all the cities listed in the vector at the time
    sort(aVector.begin(),aVector.end());
// the cityNum variable is assigned the value of count to be used outside of this function. 
  cityNum = count;

}


// this function dynamically allocates space for the flight map pointer, reads in and creates a struct for each flight record, builds the adjacency list, and then the sorts the list after each push to the list. 
void FlightMapClass::BuildFlightMap(ifstream & myIn)
{
// the function variables are declared and initalized
  int count = 0;
  flightRec flight; // flight is an instance of flightRec
  
// space is dynamically allocated for adjList (the flight map pointer)
  adjList = new list<flightRec>[cityNum];

// while the total number of cities hasn't been exceeded and there's still flight records to be read in
  while ((count < cityNum) && (myIn >> flight.flightNum))
  {
// the origin, destination, and price are read into the flightRec instance
    myIn >> flight.origin;
    myIn >> flight.destination;
    myIn >> flight.price;


// a counter variable (i) is declared and defined 
    int i = 0;
// while the end of vector hasn't been exceeded
    while (i < aVector.size()) 
    {
      
// if the flight origin matches the right city in the vector,
      if (flight.origin == aVector[i]) 
      {

// that flight is added to the end of that adjacency list 
        adjList[i].push_back(flight);
// the flights in that list are sorted in ascending order 
        adjList[i].sort(); 
// the counter variable is increased 
        i++;
      }
// otherwise, the flight origin moves onto the next element of the vector to check again
      else 
       i++;
    }

  }
// the count is increased to move onto the next flight record in the flights.dat
  count++; 
}

// this function prints out the flight map in a formatted order.
void FlightMapClass::Display()
{
// the header for the flight list is displayed 
  cout << endl;
  cout << "Origin" << setw(30) << "Destination" << setw(15) << "Flight" << setw(11) << "Price" << endl;
  cout << "==============================================================" << endl;
  cout << endl;

// an iterator of the flightRec class is declared
  list <flightRec>::iterator itr;
// for every list in the adjacency list,
  for (int i = 0; i < cityNum; i++)
  {
// if the list isn't empty, the list is printed using a certain format, otherwise that certain list is skipped
    if (!adjList[i].empty())
    {
      string message = "From " + aVector[i] + " to: ";
      cout << left << setw(25) << message;
      bool firstTime = true;
      for (itr = adjList[i].begin(); itr != adjList[i].end(); itr++)
      {
        
        if (firstTime == true)
        {
          cout << *itr << endl; 
          firstTime = false;
        }
        else 
        {
          cout << setw(25) << " ";
          cout << *itr << endl;
        }
      }
      cout << endl;
    }
  }
  
  
}
