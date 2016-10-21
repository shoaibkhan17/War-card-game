#include <iostream>
#include <cstdlib>
#include "deck.h"

using namespace std;

#pragma once
class Player
{
public:
	Deck *hand;
	Deck *SpareHand;
	int score;
	bool win;
	Player();
	~Player();
};

