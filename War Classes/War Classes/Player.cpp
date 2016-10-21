#include "Player.h"



Player::Player()
{
	hand = new Deck;
	SpareHand = new Deck;
	score = 0;
	win = false;
}


Player::~Player()
{
}
