// Class automatically generated by Dev-C++ New Class wizard

#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>

using namespace std;

class Card
{     
      private:
		  int value, rank, suit, colour;          // instance variables

	  public:
             static string ranks[13];       // class variables that keep track of
             static string suits[4];        // the values used to display the card
             
		Card();
		Card::Card(int , int , int );

		~Card();
  
        int getValue();    // Get Methods
        int getSuit();     
        int getRank();
		int getColour();

        void setValue(int);   // Set Methods
        void setSuit(int);
        void setRank(int);
		void setColour(int);			//252 - red, 240 - black


        void displayCard();  // Displays the card to the screen
                             // by referring to the values stored in the class
                             // variables
		void displayCardWithColour();
};


#endif // CARD_H
