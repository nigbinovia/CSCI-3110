/* 
 PROGRAMMER:       	Naomi Igbinovia 
 Program Description:  
  This program creates a flight map of cities based on 
  a data file of ciites provided. The cities are stored and    sorted in a vector. A build function is then used to 
  collect every origin city that can be linked to a valid 
  destination city and creates a list connecting each origin   city to every destination city it has. Then, all this data   is printed with the flight numbers and prices. 
  
*/ 

#include <iostream>
#include <iomanip>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>

#include "flightMap.h"
using namespace std;

int main() {
// the variables are declared
  ifstream myIn;
  FlightMapClass  flightMap;

// the first data file is opened and checked if it was opened correctly
  myIn.open("cities.dat");
  assert(myIn);

// all the cities in ciites.dat are read into a vector using a function 
  flightMap.ReadCities(myIn);
  
// the first data file is closed
  myIn.close();

  
// the second data file is opened and checked if it was opened correctly
  myIn.open("flights.dat");
  assert(myIn);
  
// the flight map is built using a function
  flightMap.BuildFlightMap(myIn);

// the second data file is closed
  myIn.close();

// all of the contents of the flight map is displayed using a function 
  flightMap.Display();
  
  
}
