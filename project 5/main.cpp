/* 
 PROGRAMMER:       	Naomi Igbinovia 
 Program Description:  
  This program creates a database for an online auction site using inheritance, 
  that keeps track of all the sellers. 
  
*/ 

#include <iostream>
#include <fstream>
#include <list>

// the class declaration files are called for reference
#include "Person.h"
#include "Seller.h"
#include "Powerseller.h"
using namespace std;

// the functions are declared 
void PrintSellers(list<Seller*>& listOfSellers);
void CheckSeller(list<Seller*>& listOfSellers);
void AddSeller(list<Seller*>& listOfSellers);
void RemoveSeller(list<Seller*>& listOfSellers);

int main() {

// the main function variables are declared and a few are
// initalized 
  char record;
  string first,last, user, pass;
  int check = 0;
  bool done = false;
  int choice;

// the first data file is called 
  ifstream myIn("users.dat");

// a STL list of pointers is declared with an iterator 
// for all the users in the file
  list <Person*> listOfUsers;
  list <Person*>::iterator itr;

// while the end of file hasn't been reached, 
  while(!myIn.eof())
  {
    
// a new pointer is created and its information is read
// into the pointer using the read function. The pointer
// then is pushed to the back of the list. 
    Person* user = new Person();
    user->read(myIn);
    listOfUsers.push_back(user);
    
  }

// the second data file is called and another STL list of 
// pointers is declared for all the sellers in the file 
  ifstream myIn2("sellers.dat");
  list <Seller*> listOfSellers;

// while a character can still be read in from the data file
  while(myIn2 >> record)
  {

// if the read in character is 'S', a new seller pointer is 
// created, formed with the information from the file using 
// the read function, and pushed to the back of the list 
    if (record == 'S')
    {
      Seller* seller = new Seller();
      seller->read(myIn2);
      listOfSellers.push_back(seller);
    }

// if the read in character is 'P', a new powerseller 
// pointer is created, formed with the information from
// the file using the read function, and pushed to the back 
// of the list 
    else if(record == 'P')
    {
      PowerSeller* powerseller = new PowerSeller();
      powerseller->read(myIn2);
      listOfSellers.push_back(powerseller);  
    }
  }

// the user is prompted with a login to check if they're 
// valid user for access. 
  cout << "User login: " << endl;

  cout << endl;

// the user is asked to enter their first and last name for the
// first check
  cout << "First name: ";
  cin >> first;
  cout << "Last name:  ";
  cin >> last;

// for every element in the STL user list,
  for (itr = listOfUsers.begin(); itr != listOfUsers.end(); itr++)
  {

// if the first and last name entered matches a user in the list,
    if((first == (*itr)->getFirstName()) && (last == (*itr)->getLastName()))
    {
// the check variable is verified and the user is then asked for 
// their username and password
      check = 1;
      cout << "User ID:    ";
      cin >> user;
      cout << "Password:   ";
      cin >> pass;

// if the password entered is "LETMEIN", the user is allowed access 
// to the database
      if (pass == "LETMEIN")
      {
        cout << "User authentication successful... Loading Main Menu." << endl;

        cout << endl;
        cout << endl;
        cout << endl;

// The user is prompted with the following options and asked to 
// choose one of them
        cout << "Please choose from the following menu: " << endl;
        cout << "     1. Print all seller information " << endl;
        cout << "     2. Check information of one seller " << endl;
        cout << "     3. Add a seller " << endl;
        cout << "     4. Remove a seller " << endl;
        cout << "     5. Quit " << endl;

        cout << "Enter your choice: ";
        cin >> choice;

// while the user's choice isn't equal to 5, 
        while (choice != 5)
        {
// if the user chooses 1, the PrintSellers function is called 
          if (choice == 1)
          {
            cout << endl;

            PrintSellers(listOfSellers);

            cout << endl;
            cout << endl;
            
// after the function completes, the user is again prompted with 
// the following options and asked to choose one of them
            cout << "Please choose from the following menu: " << endl;
            cout << "     1. Print all seller information " << endl;
            cout << "     2. Check information of one seller " << endl;
            cout << "     3. Add a seller " << endl;
            cout << "     4. Remove a seller " << endl;
            cout << "     5. Quit " << endl;

            cout << "Enter your choice: ";
            cin >> choice;
            
          }
            
// if the user chooses 2, the CheckSeller function is called  
          else if (choice == 2)
          {
            cout << endl;
           
            CheckSeller(listOfSellers);
            
            cout << endl;
            cout << endl;

// after the function completes, the user is again prompted with 
// the following options and asked to choose one of them            
            cout << "Please choose from the following menu: " << endl;
            cout << "     1. Print all seller information " << endl;
            cout << "     2. Check information of one seller " << endl;
            cout << "     3. Add a seller " << endl;
            cout << "     4. Remove a seller " << endl;
            cout << "     5. Quit " << endl;

            cout << "Enter your choice: ";
            cin >> choice;
            
          }

// if the user chooses 3, the AddSeller function is called              
          else if (choice == 3)
          {
            cout << endl;
            
            AddSeller(listOfSellers);

            cout << endl;
            cout << endl;

// after the function completes, the user is again prompted with 
// the following options and asked to choose one of them            
            cout << "Please choose from the following menu: " << endl;
            cout << "     1. Print all seller information " << endl;
            cout << "     2. Check information of one seller " << endl;
            cout << "     3. Add a seller " << endl;
            cout << "     4. Remove a seller " << endl;
            cout << "     5. Quit " << endl;

            cout << "Enter your choice: ";
            cin >> choice;
            
          }

// if the user chooses 2, the RemoveSeller function is called              
          else if (choice == 4)
          {
            cout << endl;
            
            RemoveSeller(listOfSellers);

            cout << endl;
            cout << endl;

// after the function completes, the user is again prompted with 
// the following options and asked to choose one of them            
            cout << "Please choose from the following menu: " << endl;
            cout << "     1. Print all seller information " << endl;
            cout << "     2. Check information of one seller " << endl;
            cout << "     3. Add a seller " << endl;
            cout << "     4. Remove a seller " << endl;
            cout << "     5. Quit " << endl;

            cout << "Enter your choice: ";
            cin >> choice;
            
          }

          else 
          {
// if the user chooses an invalid option, an error statement prints
            cout << "This is not a valid option." << endl;

            cout << endl;
            cout << endl;

// after the function completes, the user is again prompted with 
// the following options and asked to choose one of them            
            cout << "Please choose from the following menu: " << endl;
            cout << "     1. Print all seller information " << endl;
            cout << "     2. Check information of one seller " << endl;
            cout << "     3. Add a seller " << endl;
            cout << "     4. Remove a seller " << endl;
            cout << "     5. Quit " << endl;

            cout << "Enter your choice: ";
            cin >> choice;
            

            
          }

        }

// if the user's choice is equal to 5, the done flag is set to true
// and if done == true, the exit message is displayed and the program ends.
        if (choice == 5)
          done = true;

        if (done ==  true)
          cout << endl;
        
          cout << "Thank you for using BidHere.com!" << endl;
        
      }

//otherwise, the program exits
      else
        cout << "Invalid password... exit." << endl;
    }
      
  }

// if the user wasn't found is check is still 0, the program exits 
    if (check == 0)
      cout << "Invalid user... exit." << endl;
  
}

void PrintSellers(list<Seller*> & listOfSellers)
{
// an iterator for the Seller STL list is declared
  list <Seller*>::iterator itr;

// for every element of the list,
  for (itr = listOfSellers.begin(); itr != listOfSellers.end(); itr++)
  {
    
// the contents of the element is printed 
    (*itr)->print();
    cout << endl;
  }
}

void CheckSeller(list<Seller*> & listOfSellers)
{
// an iterator for the Seller STL list is declared
  list <Seller*>::iterator itr;

// function variables are declared 
  string first, last;
  int check = 0;

// the user prompted to enter to first and last name to 
// check for 
  cout << "Enter first name: ";
  cin >> first;
  cout << "Enter last name: ";
  cin >> last;

// for every element of the list,
  for (itr = listOfSellers.begin(); itr != listOfSellers.end(); itr++)
  {
// if the given first and last name match a seller in the list,
    if((first == (*itr)->getFirstName()) && (last == (*itr)->getLastName()))
    {
// the check variable is verified and the seller's contents is displayed 
      check = 1;
      (*itr)->print();
    }
  }

// otherwise, an exit message is printed 
  if (check == 0)
    cout << "Entered seller couldn't be found." << endl;

}

void AddSeller(list<Seller*> & listOfSellers)
{
// function variables are declared
  char record;
  string first, last, id, email, website;
  double rating, total, current;

// the user is asked to add either a seller or a powerseller
  cout << "Is the seller a (S)eller or (P)ower Seller? ";
  cin >> record;

// if the user enters 'S' for seller,
  if (record == 'S')
  {
// the user is prompted to enter the name, id, email, rating, and total 
// items sold
    cout << "First name: ";
    cin >> first;
    cout << "Last name: ";
    cin >> last;
    cout << "User ID: ";
    cin >> id;
    cout << "Email Address: ";
    cin >> email;
    cout << "Average Rating: ";
    cin >> rating;
    cout << "Total Items Sold: ";
    cin >> total;

// these inputs are used to call the Seller value constructor to 
// create a new seller
    Seller* seller = new Seller(first,last,id,email,rating,total);

// the seller is pushed to the back of the list 
    listOfSellers.push_back(seller);
    
  }

// if the user enters 'P' for powerseller,
  else if (record == 'P')
  {
// the user is prompted to enter the name, id, email, rating, total 
// items sold, website, and current items sold
    cout << "First name: ";
    cin >> first;
    cout << "Last name: ";
    cin >> last;
    cout << "User ID: ";
    cin >> id;
    cout << "Email Address: ";
    cin >> email;
    cout << "Average Rating: ";
    cin >> rating;
    cout << "Total Items Sold: ";
    cin >> total;
    cout << "Website: ";
    cin >> website;
    cout << "Current Items Sold: ";
    cin >> current;

// these inputs are used to call the PowerSeller value constructor to 
// create a new powerseller
    PowerSeller* powerseller = new PowerSeller(first,last,id,email,rating,total,website,current);

// the powerseller is pushed to the back of the list and the updated list 
// is printed 
    listOfSellers.push_back(powerseller);
    PrintSellers(listOfSellers);
  }

// otherwise, an erorr message is printed 
  else 
    cout << "this is not a valid option." << endl;

}

void RemoveSeller(list<Seller*> & listOfSellers) 
{
//  an iterator for the Seller STL list is declared
  list <Seller*>::iterator itr;

// the function variables are declared 
  string first, last;
  int check = 0;

// the user is asked for the first and last name of a user to remove
  cout << "Enter first name: ";
  cin >> first;
  cout << "Enter last name: ";
  cin >> last;

// for every element of the list,
  for (itr = listOfSellers.begin(); itr != listOfSellers.end();)
  {
// if the given first and last name match a seller in the list,
    if((first == (*itr)->getFirstName()) && (last == (*itr)->getLastName()))
    {
      check = 1;

// the iterator pointer and the seller are deleted 
      delete *itr;
      itr = listOfSellers.erase(itr);
      
    }

//otherwise, the iterator continues through the list
    else
      {
        itr++;
      }
      
  }

// if the seller is not found, an error message prints
  if (check == 0)
    cout << "Seller couldn't be found for removal" << endl;
}
