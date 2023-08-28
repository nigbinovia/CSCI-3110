// this is the implementation file of the Seller class

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// the Seller declaration file is included for reference 
#include "Seller.h"

// the Seller default constructor sets both the average rating
// and total sold variables to 0. 
Seller::Seller() : Person(), averageRating(0), totalSold(0)
{
}

// the Seller copy constructor sets the average rating and total 
// sold variables of Seller object 2 to be the same as Seller object 1
Seller::Seller(const Seller & source) : Person(source), averageRating(source.averageRating), totalSold(source.totalSold)
{
  averageRating = source.averageRating;
  totalSold = source.totalSold;
}

// the Seller value constructor sets the average rating and total 
// sold variables of a Seller object to whatever variables are given 
// in the function call
Seller::Seller(string newFirstName, string newLastName, string newUserID, string newEmailAddress, double newAverageRating, double newTotalSold) : Person(newFirstName, newLastName, newUserID, newEmailAddress), averageRating(newAverageRating), totalSold(newTotalSold)
{
}

// these overloaded operators input and output a Seller's information
istream& operator>> (istream& is, Seller& rhs)
{
// this function uses getline to read values from the input stream into the
// corresponding variables in the right hand side Person object.
  
	// read base class information
	string buffer;
	Person * person = &rhs;
	is >> *person;

	cout << "Average Star Rating:  ";
	getline(is, buffer);
	if( buffer[0] == '-' )
	{
		// we don't allow negative ratings
		rhs.averageRating = 0;
	}
	else
	{
		// if positive, convert string to unsigned
		rhs.averageRating = (unsigned)atoi(buffer.c_str());
	}
  cout << "Total Items sold:   ";
  getline(is, buffer);
  rhs.totalSold = (unsigned)atoi(buffer.c_str());
  
	return is;
}
ostream& operator<< (ostream& os, const Seller& rhs)
{
// this function prints values from the right hand side Person object to 
// the output stream provided as an argument to this function.
  rhs.print();

	// print the seller's information and return the output stream 
	return os;
}


// accessor functions 

// this function retrieves the Seller's average rating 
double Seller::getAverageRating() const
{
  return averageRating;
}

// this function retrieves the Seller's total items sold 
double Seller::getTotalSold() const
{
  return totalSold;
}


// virtual functions 

// this function prints an object's information from different 
// classes -- couldn't get setw() to work for some reason 
void Seller::print() const
{
  cout << "             " << "Name:  " << getFirstName() << " " << getLastName() << endl;
  cout << "          " << "User ID:  " << getUserID() << endl;
  cout << "            " << "Email:  " << getEmailAddress() << endl;
  cout << "   " << "Average Rating:  " << averageRating << endl;
  cout << " Total Items Sold:  " << totalSold << endl;
}

// this function reads in object's information from a file in 
// different classes 
void Seller::read(istream & myIn)
{
  Person::read(myIn);
  myIn >> averageRating;
  myIn >> totalSold;
}


// mutator functions 

// this function changes the Seller's average rating 
void Seller::setAverageRating(double newAverageRating)
{
  averageRating = newAverageRating;
}

// this function changes the Seller's total items sold
void Seller::setTotalSold(double newTotalSold)
{
  totalSold = newTotalSold;
}
