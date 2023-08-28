// this is the implementation file of the Seller class

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// the Powerseller declaration file is included for reference 
#include "Powerseller.h"

// the Powerseller default constructor sets the website 
// variable to "no website yet", and the current sold 
// variable to 0. 
PowerSeller::PowerSeller() : Seller(), website("No website yet"), currentSold(0)
{
}

// the Powerseller copy constructor sets the average rating 
// and total sold variables of Powerseller object 2 to be the
// same as Seller object 1
PowerSeller::PowerSeller(const PowerSeller & source) : Seller(source), website(source.website), currentSold(source.currentSold)
{
  website = source.website;
  currentSold = source.currentSold;
}

// the Powerseller value constructor sets the average rating 
// and total sold variables of a Powerseller object to whatever 
// variables are given in the function call
PowerSeller::PowerSeller(string newFirstName, string newLastName, string newUserID, string newEmailAddress, double newAverageRating, double newTotalSold, string newWebsite, double newCurrentSold) : Seller(newFirstName, newLastName, newUserID, newEmailAddress, newAverageRating, newTotalSold), website(newWebsite), currentSold(newCurrentSold)
{
}


// these overloaded operators input and output a Powerseller's information
istream& operator>> (istream& is, PowerSeller& rhs)
{
//This function uses getline to read values from the input stream 
//into the corresponding variables in the right hand side PowerSeller object.
	string buffer;
	Seller * seller = &rhs;

	// get base class information

	is >> *seller;

	cout << "Website Address:  ";
	getline(is,rhs.website);

	cout << "Current year products Sold:  ";
	getline(is,buffer);
	if( buffer[0] == '-' )
	{
		// we don't allow negative numbers
		rhs.currentSold = 0;
	}
	else
	{
		// if positive, convert string to unsigned
		rhs.currentSold = (unsigned)atoi(buffer.c_str());
	}

	return is;
}
ostream& operator<< (ostream& os, const PowerSeller& rhs)
{
// This function prints values from the right hand side PowerSeller object 
// to the output stream provided as an argument to this function.
  
  // print base class information
  rhs.print();

	// print PowerSeller information


	os << "           Website Address: " << rhs.website << endl;
	os << "Current Year Products Sold: " << rhs.currentSold << endl;


	// print the seller's information and return the output stream 
	return os;
}


// accessor functions 

// this function retrieves the Powerseller's website
string PowerSeller::getWebsite() const
{
  return website;
}

// this function retrieves the Powerseller's current 
// items sold 
double PowerSeller::getCurrentSold() const
{
  return currentSold;
}


// virtual functions 

// this function prints an object's information from different 
// classes -- couldn't get setw() to work for some reason 
void PowerSeller::print() const 
{
  cout << "             " << "Name:  " <<  getFirstName() << " " << getLastName() << endl;
  cout << "          " << "User ID:  " << getUserID() << endl;
  cout << "            " << "Email:  " << getEmailAddress() << endl;
  cout << "   " << "Average Rating:  " << getAverageRating() << endl;
  cout << " Total Items Sold:  " << getTotalSold() << endl;
  cout << "          " << "Website:  " << website << endl;
  cout << "     " << "Current Sale:  " << currentSold << endl;
}

// this function reads in object's information from a file from
// different classes 
void PowerSeller::read(istream & myIn) 
{
  Seller::read(myIn);
  myIn >> website;
  myIn >> currentSold;
}


// mutator functions 

// this function changes the Powerseller's website
void PowerSeller::setWebsite(string newWebsite)
{
  website = newWebsite;
}

// this function changes the Powerseller's current items sold
void PowerSeller::setCurrentSold(double newCurrentSold)
{
  currentSold = newCurrentSold;
}
