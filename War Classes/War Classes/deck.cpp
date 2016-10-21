#include "deck.h"
#include <iostream>
#include <ctime>
#include "utility.h"

using namespace std;

Deck::Deck()
{
	top=-1;
}

Deck::~Deck()
{           
}

void Deck::setTop(int _top)       // set method for the property top
{    top = _top;
     return;
}

int Deck::getTop()                // get method for the property top
{   return top;
}

Card* Deck::getCard(int n)
{    // Returns a pointer to the card at position n of the array.
     
     if ((n > getTop()) || (n < 0))
     {  cout << "ERROR: NOT A VALID POSITION IN THE ARRAY" << endl;
        return NULL;
     }
     else
     {    return &(pile[n]);
     }
}

void Deck::initializeDeck()        
{   // initializes the values of the deck.
    // this assumes a deck of 52 cards
    
    setTop(51);                   
    for (int i=0; i<52; i++)
    {   pile[i].setSuit(i%4);
        pile[i].setRank(i%13);
    }
    return;
}

void Deck::initializeColour()
{
	for (int i = 0; i < 52; i++)
	{
		if ((pile[i].getSuit() == 1) || (pile[i].getSuit() == 2))
		{
			pile[i].setColour(252);
		}

		else
		{
			pile[i].setColour(240);
		}
	}
}

void Deck::displayDeck(bool withNumbers)   
{    // Displays the contents of the deck by asking each card to display itself
     for (int i= getTop(); i>=0; i--)
     {   if (withNumbers)
         {  cout << (getTop()+1)-i << ") ";
         }
         pile[i].displayCard();
     }
     return;
}

void Deck::displayDeckWithColour(bool withNumbers)
{    // Displays the contents of the deck by asking each card to display itself

	for (int i = getTop(); i >= 0; i--)
	{
		Utility::changeColour(9);
		if (withNumbers)
		{
			cout << (getTop() + 1) - i << ") ";
		}
		pile[i].displayCardWithColour();
		Utility::changeColour(7);
	}
	return;
}

void Deck:: shuffleDeck()         
{    // Shuffles the deck by repeatedly swapping two random cards
     
     Card temp;
     int temp1, temp2 = 0;
     srand(time(NULL));
     for (int i=0; i <1000; i++)
     {   temp1=rand()%(getTop()+1);
         temp2=rand()% (getTop() + 1);
         temp = pile[temp1];
         pile[temp1]=pile[temp2];
         pile[temp2]=temp;
     }
     return;
}



void Deck::dealCard(Deck *destination)           
{ // Deals the top card of the deck to the deck pointed 
  // to by the pointer called destination
  
  destination->setTop(destination->getTop()+1);
  destination->pile[destination->getTop()]=pile[getTop()];
  setTop(getTop()-1);
}


void Deck::moveCard(Deck *destination, int n)
{  // Accepts a pointer to a deck and an integer
   // The integer n represent the position in the deck of the card being moved
   // The pointer destination represent the deck to which the card will be moved.
  
   destination->top++;
   //destination->setTop(destination->getTop()+1);  // Increases the value of top.        
   destination->pile[destination->getTop()] = pile[n]; // Sets the top card of the destination deck to the card being moved.
   rebalanceHand(n);                    // rebalances the deck now that the card has been moved
   setTop(getTop()-1);                  // decreases the top of the deck since there is one fewer card
}


void Deck::rebalanceHand(int n)
{    // After the card in position n is removed from the hand it needs 
     // to be removed from the array and all other cards shifted down.
     
     for (int i=n; i < getTop(); i ++)
     {   pile[i]= pile[i+1];
     }
}

void Deck:: sortHand()            
{    // Sorts the deck by suit and rank.
     // Each card can be given a unique value between 0 and 51 
     // calculated as (4 x the suit value) + (the rank value)
     
     Card temp;
     
     for (int i=0; i <= getTop()-1; i++)
     {   for (int j=i+1; j <= getTop(); j++)
         {   
             if (((13*pile[i].getSuit()) + (pile[i].getRank())) < ((13*pile[j].getSuit())+ (pile[j].getRank())))
             {  temp = pile[i];
                pile[i]= pile[j];
                pile[j]= temp;
             }              
         }
      }    
}
