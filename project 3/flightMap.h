#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
using namespace std;

#ifndef FLIGHTMAPCLASS_H
#define FLIGHTMAPCLASS_H

#include "type.h"

using namespace std;

class FlightMapClass
{
// all the methods are declared in the public section of the class
  public:
// the default constructor, copy constructor, and deconstructor are declared 
    FlightMapClass();
    FlightMapClass(const FlightMapClass & rhs); 
    ~FlightMapClass();
		
	
		//FlightMapClass operations:

		//Read cities from a data file
		//Pre-condition: Input stream is provided
		//Post-condition: Data file is read
		//				  Cities are in ascending order
    void ReadCities(ifstream & myIn);


		//Reads flight information and build the adjacency list
		//Pre-condition: list of the flight information is provided
		//Post-condition: Flight map is built
		void BuildFlightMap(ifstream & myIn);
		
		//Displays the flight map in a formatted table
    // using overloaded << opererator
		//Pre-condition: none
		//Post-condition: Flight map is displayed
    void Display();
		
	private:
    int cityNum;    //number of cities
    vector <string> aVector;    //vector of cities
		list <flightRec> *adjList;  //flight map
};

#endif
