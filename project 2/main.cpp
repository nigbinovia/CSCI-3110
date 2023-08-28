/* 
 PROGRAMMER:       	Naomi Igbinovia
 Program Description:    
  This program uses a Card, Deck, and Player class to build 
  an interactive card game between the user and the computer.
  There are 26 rounds and whoever's card has the higher point value 
  wins the round. 
*/ 


#include <iostream>
#include <cstring>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
using namespace std;

int main() {
// the variables are declared and initalized 
  int count = 1;
  Card cpuCard;
  Card userCard;

// a Deck object is created and printed 
  Deck Deck1;
  cout << "Initial Deck of Cards: " << endl;
  cout << Deck1 << endl;
  cout << "=== end Initial Deck Cards === " << endl;
  cout << endl;

// the deck object is shiffled and printed again
  Deck1.shuffle();
  cout << "After Shuffle the Cards:" << endl;
  cout << Deck1 << endl;
  cout << " === end Shuffled Cards === " << endl;
  cout << endl;
  cout << endl;
  

// two Player objected are created called "Computer"
// and "Joey"
  Player CPU("Computer");
  Player User("Joey");

// 3 cards are drawn for the Computer hand and 3
// cards are drawn for the User hand 
  CPU.drawCard(Deck1);
  CPU.drawCard(Deck1);
  CPU.drawCard(Deck1);

  User.drawCard(Deck1);
  User.drawCard(Deck1);
  User.drawCard(Deck1);

// for rounds 1 through 24,
  while (count < 24) 
  {
// the current scores are printed with the current 
// round number 
    cout << "=======================" << endl;
    cout << "Round " << count << " of 26 "<< endl;
    cout << "Computer's score: " << CPU.getScore() << endl;
    cout << "Joey's score: " << User.getScore() << endl;
    cout << "=======================" << endl;
    cout << endl;

//the computer's hand is printed 
    cout << "Computer: " << endl;
    cout << CPU << endl;

//the user's hand is printed 
    cout << "---------------------" << endl;
    cout << "Here are your cards: " << endl;
    cout << User << endl;

// the computer and the user choose their hand 
// that are assinged to their own Card variables 
    cpuCard = CPU.playCard();
    userCard = User.playCard();
    cout << endl;

// Card variables are printed and compared to find
// the winner 
    cout << "Computer played: " << cpuCard << endl;
    cout << "Joey played: " << userCard << endl;

// if the computer wins both cards' points are added to 
// the computer's score and the computer is printed as the 
// winner 
    if (cpuCard > userCard)
    {
      CPU.addScore(cpuCard);
      CPU.addScore(userCard);
      cout << "Computer wins the hand, added " << CPU.getScore() << " points" << endl;
    }

// if the user wins both cards' points are added to 
// the user's score and the user is printed as the winner
    else 
    {
      User.addScore(userCard);
      User.addScore(cpuCard);
      cout << "Joey wins the hand, added " << User.getScore() << " points" << endl;
    }

    
    CPU.drawCard(Deck1);
    User.drawCard(Deck1);
    
    count++;

    cout << endl;
    cout << "=======================" << endl;
    
  }


// for the remaining rounds, the same loop cotinues, just without 
// cards being drawn near the end of the game 
  {
    
    cout << "Round " << count << endl;
    cout << "Computer's score: " << CPU.getScore() << endl;
    cout << "Joey's score: " << User.getScore() << endl;
    cout << endl;

    cout << "Computer: " << endl;
    cout << CPU << endl;
    cout << endl;

    cout << "Here are your cards: " << endl;
    cout << User << endl;
    cpuCard = CPU.playCard();
    userCard = User.playCard();
    cout << endl;

    cout << "Computer played: " << cpuCard << endl;
    cout << "Joey played: " << userCard << endl;

    if (cpuCard > userCard)
    {
      CPU.addScore(cpuCard);
      CPU.addScore(userCard);
      cout << "Computer wins the hand, added " << CPU.getScore() << " points"<< endl;
    }
    
    else 
    {
      User.addScore(userCard);
      User.addScore(cpuCard);
      cout << "Joey wins the hand, added " << User.getScore() << " points" << endl;
    }

    
    count++;

    cout << "--------------------------------------------" << endl;

    cout << endl;
    
  }

  int cpuFinal = CPU.getScore();
  int userFinal = User.getScore();

// the final scores aren printed and the winner is announced 
  cout <<  "=== END OF GAME ==="  << endl;

  cout << "Computer's score: " << cpuFinal << endl;
  cout << "Joey's score: " << userFinal << endl;
  
  if (cpuFinal > userFinal)
  {
    cout << "Computer wins!" << endl;
  }
  else 
  {
    cout << "Joey wins!" << endl;
  }
    

  


  

}
