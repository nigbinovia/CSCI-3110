// this is the declaration file of the Person class

// along with #endif, precent mutlplie inclusion of the Person 
// class definition
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person
{
// all the methods of the Person class are declared in the 
// public section 
public:

// the default constructor, copy constructor, and the value 
// constructor are declared 
	Person();
	Person(const Person& source);
	Person(string newFirstName, string newLastName, string newUserID, string newEmailAddress);


// overloaded operators 

// these operators compare the first names, last names, and email
// addresses of two Persons
	bool operator== (const Person& rhs) const;
	bool operator!= (const Person& rhs) const;

// these operators compare the last names of two Persons
	bool operator< (const Person& rhs) const;
	bool operator> (const Person& rhs) const;

// this operator assigns one Person's infomation to another 
	Person& operator= (const Person& rhs);

// these overloaded operators input and output a Person's information
	friend istream& operator>> (istream& is, Person& rhs);
	friend ostream& operator<< (ostream& os, Person& rhs);


// accessor functions 

// this function retrieves the Person's first name
	string getFirstName() const;

// this function retrieves the Person's last name
	string getLastName() const;

// this function retrieves the Person's email address
	string getEmailAddress() const;

// this function retrieves the Person's user id 
	string getUserID() const;


// virtual functions

// this function prints an object's information in different 
// classes 
  virtual void print() const;

// this function reads in object's information from a file in 
// different classes 
  virtual void read(istream & myIn);


// mutator functions 

// this function changes the Person's first name 
	void setFirstName(const string& newFirstName);

// this function changes the Person's last name 
	void setLastName(const string& newLastName);

// this function changes the Person's email address
	void setEmailAddress(const string& newEmailAddress);

// this function changes the Person's user id 
	void setUserID(const string& newUserID);


// variable declarations of the Person class 
protected:
	// first name of a Person
	string firstName;
	// last name of a Person
	string lastName;
	// user ID of a Person
	string userID;
	// email address of a Person
	string emailAddress;
};

#endif
