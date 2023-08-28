#include "Player.h"

// this constructor creates a Player object by 
// creating an empty hand and setting the score 
// to 0
Player::Player(string pname) : name(pname)
{
  score = 0;
  
  for (int i = 0; i < Max_Cards; i++)
  {
    played[i] = true;
  }
   
}

// this function determines which card is returned
// depending on the Player
Card Player::playCard()
{
// variables are declared and initalized 
    string n = getName();
    int choice1 = 0;
    int choice2 = 0;
    int max = 0;

// if the Player name is equal to "Computer"
// the code for the Computer is followed 
  if (n == "Computer") 
  {
// if there's only one card in the computer's hand 
// the card is printed and returned 
    if ((played[1] == true) && (played[2] == true)) 
    {
      cout << "Computer played: " << hand[0] << endl;
      return hand[0];
    }
// if there's two cards in the computer's hand 
    else if (played[2] == true) 
    {
// the max is reset to 0;
      max = 0;
// for every card in the computer's hand 
      for (int i = 0; i < 2; i++)  
      {
// if a larger point value is found, the max value is
// set to the larger point value and the choice variable 
// is set to the current index 
        if (hand[i].getPointValue() > max)
        {
          max = hand[i].getPointValue();
          choice1 = i;
        }
      }
// postloop, the best option is returned and its location
// in the played array is set true 
      played[choice1] = true;
      return hand[choice1];
    }
      
// if there's three cards in the computer's hand 
    else 
    {
// the max is reset to 0;
      max = 0;
// for every card in the computer's hand 
      for (int i = 0; i < 3; i++) 
      {
// if a larger point value is found, the max value is
// set to the larger point value and the choice variable 
// is set to the current index 
        if (hand[i].getPointValue() > max) 
        {
          max = hand[i].getPointValue();
          choice1 = i;
        }
      }
// postloop, the best option is returned and its location
// in the played array is set true 
      played[choice1] = true;
      return hand[choice1];
      
    }
  }

// if the Player name is the user 
// the code for the User is followed 
  else 
  {
// if there's only one card in the user's hand 
// the card is printed and returned 
    if ((played[1] == true) && (played[2] == true)) 
    {
      cout << n << "played: " << hand[0] << endl;
      return hand[0];
     }
    else if ((played[0] == true) && (played[1] == true)) 
    {
      cout << n << "played: " << hand[1] << endl;
      return hand[2];
     }
    if ((played[0] == true) && (played[2] == true)) 
    {
      cout << n << "played: " << hand[1] << endl;
      return hand[1];
     }

// if there's two cards in the computer's hand, a loop runs to make 
// sure the user picks a valid option. When 1 or 2 is chosen, the 
// matching index in the played array is set to true, the card is
// is printed and the card is returned 
    else if (played[0] == true) 
    {
      while ((choice2 != 1) && (choice2 != 2)) 
      {
        cout << "Select one card to play (enter 1 or 2): " << endl;
        cin >> choice2;
      }
      if (choice2 == 1) 
      {
        played[1] = true; 
        cout << n << "played: " << hand[1] << endl; 
        return hand[1]; 
      }
      else 
      {
       played[2] = true;
       cout << n << "played: " << hand[2] << endl;
       return hand[2];
      }
    }
    else if (played[1] == true) 
    {

      while ((choice2 != 1) && (choice2 != 2)) 
      {
        cout << "Select one card to play (enter 1 or 2): " << endl;
        cin >> choice2;
      }

      if (choice2 == 1) 
      {
       
        played[0] = true; 
        cout << n << "played: " << hand[0] << endl; 
        return hand[0]; 
      }
      else 
      {
      
       played[2] = true;
       cout << n << "played: " << hand[2] << endl;
       return hand[2];
      }
    }
    else if (played[2] == true) 
    {
      while ((choice2 != 1) && (choice2 != 2)) 
      {
        cout << "Select one card to play (enter 1 or 2): " << endl;
        cin >> choice2;
      }
      
      if (choice2 == 1) 
      {
        played[0] = true; 
        //cout << n << "played: " << hand[0] << endl; 
        return hand[0]; 
      }
      else 
      {
       played[1] = true;
       cout << n << "played: " << hand[1] << endl;
       return hand[1];
      }
    }

// if there's three cards in the computer's hand, a loop runs to make 
// sure the user picks a valid option. When 1, 2, or 3 is chosen, the 
// matching index in the played array is set to true, the card is
// is printed and the card is returned 
    else 
    {
    
      while ((choice2 < 1) || (choice2 > 3)) 
      {
        cout << "Select one card to play (enter 1, 2, or 3): " << endl;
        cin >> choice2;
      }
      if (choice2 == 1)
      {
        played[0] = true;
        return hand[0];
      }
      else if (choice2 == 2)
      {
       played[1] = true;
       return hand[1];
      }
      else 
      {
        played[2] = true;
        return hand[2];
     }
      
  }
}
    
}


// this function draws a card and adds it 
// to the hand array 
void Player::drawCard(Deck & dk)
{
// for every card in the current array 
  for (int i = 0; i < Max_Cards; i++)
  {
// if the current index in the played array is set to 
// true, the dealCard function is called draw a card from 
// theDeck to the hand array and the played array index 
// is set to false 
    if (played[i] == true)
    {
      hand[i] = dk.dealCard();
      played[i] = false; 
      break;
    }
  } 
}

// this function adds the point value of the 
// card to the score of the Player 
void Player::addScore(Card oneCard) 
{
  score = score + oneCard.getPointValue();
}

// this function returns the current score of 
// the Player
int Player::getScore() const
{
  return score;
}

// this function returns the name of the Player
string Player::getName() const
{
  return name;
}

// this function returns true if no more cards are
// in the Player's hand, otherwise it returns false
bool Player::emptyHand() const
{
// a bool variable is declared and initalized 
  bool check = true;

// if one card is in play, if said card is true,
// true is returned, otherwise false is returned
  if ((played[1] == true) && (played[2] == true))
  {
    if (played[0] == true)
      return true;
    return false;
  }

// if two cards are in play, if both cards are true,
// true is returned, otherwise false is returned
  else if(played[2] == true) 
  {
    for (int i = 0; i > 2; i++)
    {
      if (played[i] == false) // if card found
        check = false;
    }
    if (check == false)
      return false;
    return true;
  }

// if three cards are in play, if a false card is 
// found, false is retruned, otherwise true is returned
  else 
  {
    for (int i = 0; i > 3; i++)
    {
      if (played[i] == false) // if card found
        check = false;
    }
    if (check == false)
      return false;
    return true;
  }
}

    // overload the << operator to display all cards in player's hand
ostream& operator << (ostream& os, const Player& rhs)
{
// if one card is left in the hand, the card is printed 
  if ((rhs.played[1] == true) && (rhs.played[2] == true))
  {
    os << "1  " << rhs.hand[0] << endl;
  }
  else if ((rhs.played[0] == true) && (rhs.played[2] == true))
  {
    os << "1  " << rhs.hand[1] << endl;
  }
  else if ((rhs.played[0] == true) && (rhs.played[1] == true))
  {
    os << "1  " << rhs.hand[2] << endl;
  }

// if two cards are left in the hand, the cards are printed 
  else if ((rhs.played[0] == true))
  {
    os << "1  " << rhs.hand[1] << endl;
    os << "2  " << rhs.hand[2] << endl;
    }

  else if ((rhs.played[1] == true))
  {
    os << "1  " << rhs.hand[0] << endl;
    os << "2  " << rhs.hand[2] << endl;
  }

  else if ((rhs.played[2] == true))
  {
    os << "1  " << rhs.hand[0] << endl;
    os << "2  " << rhs.hand[1] << endl;
    }

// if threee cards are in the hand, all cards are printed 
  else
  {
    os << "1  " << rhs.hand[0] << endl;
    os << "2  " << rhs.hand[1] << endl;
    os << "3  " << rhs.hand[2] << endl;
  }
  return os;
}
