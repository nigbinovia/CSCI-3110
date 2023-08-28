// this is the declaration file of the Seller class

// along with #endif, precent mutlplie inclusion of the Seller
// class definition
#ifndef SELLER_H
#define SELLER_H

#include <iostream>
#include <fstream>
#include <string>

// the Person declaration file is included for reference 
#include "Person.h"


// all the methods of the Seller class are declared in the 
// public section, and is set as a derived class of Person
class Seller : public Person
{
public:

// the default constructor, copy constructor, and the value 
// constructor are declared 
	Seller();
	Seller(const Seller & source);
	Seller(string newFirstName, string newLastName, string newUserID, string newEmailAddress, double newAverageRating, double newTotalSold);


// accessor functions 

// this function retrieves the Seller's average rating 
  double getAverageRating() const;

// this function retrieves the Seller's total items sold 
  double getTotalSold() const;


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

// this function changes the Seller's average rating 
  void setAverageRating(double newAverageRating);

// this function changes the Seller's total items sold 
  void setTotalSold(double newTotalSold);


// variable declarations of the Seller class 
  double averageRating;
  double totalSold;

};

#endif
