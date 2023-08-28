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
