// this is the declaration file of the Powerseller class

// along with #endif, precent mutlplie inclusion of the 
// Powerseller class definition
#ifndef POWERSELLER_H
#define POWERSELLER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// the Seller declaration file is included for reference 
#include "Seller.h"

// all the methods of the Seller class are declared in the 
// public section, and is set as a derived class of Seller
class PowerSeller : public Seller
{
public:
// the default constructor, copy constructor, and the value 
// constructor are declared 
	PowerSeller();
	PowerSeller(const PowerSeller & source);
	PowerSeller(string newFirstName, string newLastName, string newUserID, string newEmailAddress, double newAverageRating, double newTotalSold, string newWebsite, double newCurrentSold);


// accessor functions 

// this function retrieves the Powerseller's wesbite
  string getWebsite() const;

// this function retrieves the Powerseller's current items sold
  double getCurrentSold() const;


// virtual functions 
  // here the functions are overrided to be used in a new 
  // class with added variables 

// this function prints an object's information in different 
// classes 
  void print() const override;

// this function reads in object's information from a file in 
// different classes 
  void read(istream & myIn) override;

// mutator functions 

// this function changes the Powerseller's website 
  void setWebsite(string newWebsite);

// this function changes the Powerseller's current items sold
  void setCurrentSold(double newCurrentSold);


// variable declarations of the Powerseller class 
  string website;
  double currentSold;

};

#endif
