/* 
 PROGRAMMER:       	Naomi Igbinovia 
 Program Description:    
This program solves four different recursive problems regarding the     fibonacci sequence, finding the sum of integers, finding the largest integer, and finding eagles on a coordinate plane.
*/ 

#include <iostream>
#include <fstream>
#include <cassert>
#include "parameters.h"

using namespace std;

//the function declarations are made 
int Fibonacci (int FibVal);
int Sum (int SumVal);
int Largest (const int LargestVal[], int first, int last);
int FindEagle(int array[50][50], int a, int b);
int main() {

// the variables are declared 
  ifstream myIn;
  int a,b;
  int eagleCount = 0;

// for every integer less than or equal to the FibVal variable, the Fibonacci function is called, computed, and displayed with said value 
  cout << "Problem 1: " << endl;
  cout << "The first " << FibVal << " numbers in the Fibonacci sequence are: " << endl;
  for (int i = 0; i <= FibVal; i++)
    {
      cout << Fibonacci(i) << " "; 
    }
  cout << endl;
  cout << endl;


// the Sum function is called using a determined variable to compute and display the sum of integers for said variable.
  cout << "Problem 2: " << endl;
  cout << "The sum of integers for given number " << SumVal << " is: " << endl;
  cout << Sum(SumVal)<< endl;

  cout << endl;

  
  cout << "Problem 3: " << endl;
// the size of the array is computed by dividing the size of the given array by the size of an integer type. This is stored in the len variable to be passed into the Largest function. 
  int len  = ((sizeof(LargestVal))/sizeof(int));

// the Largest function is called with the given array, starting index, and array length to find and display the largest number in the given array 
  cout << "The largest number in a given array is: " << endl;
  cout << Largest(LargestVal,0,len) << endl;

  cout << endl;

  
  cout << "Problem 4: " << endl;
//the data file is opened and checked whether it was opened correctly or not
  myIn.open("eagle.dat");
  assert(myIn);

// the first two values are read into the variables a and b to set the custom (but not maximum) sizes for the first 2D array, and the first 2D is declared and defined with the maximum sizes. 
  while (myIn >> a >> b)
  {
    int eagle1[50][50];

// allowing access to every row and every column of the custom bounds, values are read in and printed from the datafile until the custom size is full. 
    for (int i = 0; i < a; i++)
    {
      for (int j = 0; j < b; j++)
      {
        int x;
        myIn >> x;
        eagle1[i][j] = x;
        cout << eagle1[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;

// allowing access to every row and every column of the custom bounds, if a non-zero is found in the array, the FindEagle function is called to count how many cells are counted towards an eagle. The size of each found eagle is displayed and each eagle is counted for a total to be printed at the end of the search 
    for (int i = 0; i < a; i++)
    {
      for (int j = 0; j < b; j++)
      {
        if ((eagle1[i][j]) != 0)
        {
          cout << "An eagle size " << FindEagle(eagle1,i,j) << " is found." << endl;
          eagleCount++;
        }
      }
    }
   cout << endl;
   cout << eagleCount << " eagle(s) found in the picture." << endl;
    cout << endl;
    eagleCount = 0;
  }
  

// the datafile is closed
  myIn.close();  
}

int Fibonacci (int FibVal)
{
//if FibVal is equal to 0 or 1, their value is the same in the Fibonacci sequence, so the value is returned
  if ((FibVal == 0) || (FibVal == 1))
    return (FibVal);

// otherwise the n value is added onto until the needed number of numbers are returned 
  else 
    return ((Fibonacci(FibVal - 1) + Fibonacci(FibVal - 2)));
}

int Sum (int SumVal)
{
// if SumVal is less than or equal to 1, no addition can be done, so the function returns said value
  if ((SumVal <= 1))
        return (SumVal);
// otherwise the value is built onto n times until the needed result is obtained 
  else
    return SumVal + Sum(SumVal - 1);
}

int Largest (const int LargestVal[], int first, int last)
{
// function variables are declared
  int max;
// if the first and last array index match, is value is returned 
  if (first == last)
    return LargestVal[first];
// otherwise, the first max value is computed. Then, it's tested against every other element in the array. 
  max = Largest(LargestVal, first + 1, last);

// if the current tested value is larger than the max, the max is reassigned to the current tested value. Otherwise the max stays the same. 
  if (LargestVal[first] > max)
    return LargestVal[first];
  else
    return max;
}

int FindEagle(int array[50][50], int a, int b)
{
// a count variable is declared to track the size of an eagle 
  int count = 0;

// this double checks that the passed value is a non-zero, if not, the count is returned to the function 
  if (array[a][b] == 0)
    return count;

// otherwise, the non-zero value is set equal to zero, count is increased to track the eagle size, and all surrounding coordinates of the given value are checked to be non-zero as well. If they are, the same process reoccurs. 
  else 
  {
    array[a][b] = 0;
    count++;
    if ((a - 1 > -1)  && (b - 1 > -1))
      count += FindEagle(array, a - 1, b - 1);

    if (a - 1 > -1 ) 
      count += FindEagle(array, a - 1, b);

    if ((a - 1 > -1 ) && (b + 1 < 50))
      count += FindEagle(array, a - 1, b + 1);

    if (b - 1 > -1) 
      count += FindEagle(array, a, b - 1);

    if(b + 1 < 50)
      count += FindEagle(array, a, b + 1);

    if ((a + 1 < 50) && (b - 1 > -1))
      count += FindEagle(array, a + 1, b - 1);

    if (a + 1 < 50)
      count += FindEagle(array, a + 1, b);

    if ((a + 1 < 50)&& (b + 1 < 50))
      count += FindEagle(array, a + 1, b + 1);  
  }
  // after the eagle size has been tracked in total, it's returned 
  return count;  
}
