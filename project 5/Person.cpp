// this is the implementation file of the Person class

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

// the Person declaration file is included for reference 
#include "Person.h"

// the Person default constructor sets all the Person 
// variables to a version of "no variable yet"
Person::Person() : firstName("No first name yet"), lastName("No last name yet"), userID("No user id yet"), emailAddress("No email address yet")
{
  
}

// the Person copy constructor sets the first name, last name 
// user id, and email address variables of Person object 2 to 
// be the same as Person object 1
Person::Person(const Person & source)
{
  firstName = source.firstName;
  lastName = source.lastName;
  userID = source.userID;
  emailAddress = source.emailAddress;
}

// the Person value constructor sets the first name, last name 
// user id, and email address variables of a Person object to 
// whatever variables are given in the function call
Person::Person(string newFirstName, string newLastName, string newUserID, string newEmailAddress) : firstName(newFirstName), lastName(newLastName), userID(newUserID), emailAddress(newEmailAddress)
{
  
}

// overloaded operators 

// these operators compare the first names, last names, and email
// addresses of two Persons
bool Person::operator == (const Person & rhs) const
{
// if the first name, last name, an email address of Person object 1
// matches these variables of Person object 2, the function returns true
// otherwise, false is returned 
  if ((firstName == rhs.firstName) && (lastName == rhs.lastName) && (emailAddress == rhs.emailAddress))
    return true;
  else
    return false;
}
bool Person::operator != (const Person & rhs) const
{
// if the first name, last name, an email address of Person object 1
// matches these variables of Person object 2, the function returns false
// otherwise, true is returned 
  if ((firstName == rhs.firstName) && (lastName == rhs.lastName) && (emailAddress == rhs.emailAddress))
    return false;
  else
    return true;
}

// these operators compare the last names of two Persons
bool Person::operator < (const Person & rhs) const
{
// if object 1's last name is succeeds object 2's last name, the 
// function returns true. Otherwise, false is returned
  if (lastName < rhs.lastName)
    return true;
  else
    return false;
}
bool Person::operator > (const Person & rhs) const
{
// if object 1's last name is preceeds object 2's last name, the 
// function returns true. Otherwise, false is returned
  if (lastName > rhs.lastName)
    return true;
  else
    return false;
}

// this operator assigns one Person's infomation to another 
Person & Person::operator = (const Person & rhs)
{
// if object 1 doesn't match object 2, all the variables of 
// of object 2 are set to match object 1.
  if (this != &rhs)
  {
    firstName = rhs.firstName;
    lastName = rhs.lastName;
    userID = rhs.userID;
    emailAddress = rhs.emailAddress;
  }
  return *this; 
    
}


// these overloaded operators input and output a Person's information
istream& operator>> (istream& is, Person& rhs)
{
// this function uses getline to read values from the input stream into the
// corresponding variables in the right hand side Person object.
	cout << "First name:  ";
	getline(is,rhs.firstName);

	cout << "Last name:  ";
	getline(is,rhs.lastName);

	cout << "User ID:  ";
	getline(is,rhs.userID);

	cout << "Email Address:  ";
	getline(is,rhs.emailAddress);

	return is;
}
ostream& operator<< (ostream& os, Person& rhs)
{
// this function prints values from the right hand side Person object to 
// the output stream provided as an argument to this function.
  
	// allow the incoming argument to have a valid this pointer
	// (so we can actually call functions from it)
	//Person * person = (Person *)&rhs;

	// print person information and return the output stream
	os << " Name: " << rhs.getFirstName() << rhs.getLastName() << endl;
	os << " User ID: " << rhs.userID << endl;
	os << " Email: " << rhs.emailAddress << endl;

	return os;
}


// accessor functions 

// this function retrieves the Person's first name
string Person::getFirstName() const
{
  return firstName;
}

// this function retrieves the Person's last name
string Person::getLastName() const
{
  return lastName;
}

// this function retrieves the Person's user id
string Person::getUserID() const
{
  return userID;
}

// this function retrieves the Person's email address 
string Person::getEmailAddress() const
{
  return emailAddress;
}


//virtual functions 

// this function reads in object's information from a file in 
// different classes 
void Person::read(istream & myIn)
{
  myIn >> firstName;
  myIn >> lastName;
  myIn >> userID;
  myIn >> emailAddress;
}

// this function prints an object's information in different 
// classes 
void Person::print() const
{
  cout << firstName << " "<< lastName << endl;
  cout << userID << endl;
  cout << emailAddress << endl;
}


// mutator functions

// this function changes the Person's first name 
void Person::setFirstName(const string & newFirstName)
{
  firstName = newFirstName;
}

// this function changes the Person's last name 
void Person::setLastName(const string & newLastName)
{
  lastName = newLastName;
}

// this function changes the Person's user id
void Person::setUserID(const string & newUserID)
{
  userID = newUserID;
}

// this function changes the Person's email address 
void Person::setEmailAddress(const string & newEmailAddress)
{
  emailAddress = newEmailAddress;
}
