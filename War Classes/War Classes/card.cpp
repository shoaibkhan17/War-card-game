#include "card.h"
#include "utility.h"


// These are class variables. They can be called from anywhere. These belong to
// every instance of the class Card.
string Card::suits[4] = {"Clubs", "Hearts", "Diamonds", "Spades"};
string Card::ranks[13] ={"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack","Queen", "King", "Ace"};

// class constructor
Card::Card()
{   suit=0;
    value=0;
}


Card::Card(int _suit, int _rank, int _value)
{     suit = _suit;
      rank = _rank;
      value = _value;
}


// class destructor
Card::~Card()
{
}

// Get for the properties of class Card
int Card::getValue()
{   return value;
}

int Card::getSuit()
{   return suit;
}

int Card::getRank()
{   return rank;
}

int Card::getColour()
{
	return colour;
}

// Get for the properties of class Card
void Card::setValue(int _value)
{    value = _value;
}

void Card::setSuit(int _suit)
{    suit = _suit;
}

void Card::setRank(int _rank)
{    rank = _rank;
}

void Card::setColour(int _colour)
{
	colour = _colour;
}

void Card::displayCard()     // Displays the card to the screen
                             // by referring to the values stored in the class
                             // variables
{    cout << Card::ranks[getRank()] << " of " << Card::suits[getSuit()] << endl;    
}

void Card::displayCardWithColour()
{
	Utility::changeColour(getColour());
	cout << Card::ranks[getRank()] << " of " << Card::suits[getSuit()] << endl;
}