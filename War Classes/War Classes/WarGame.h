#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "deck.h"
#include "Player.h"
#include "utility.h"

using namespace std;

#pragma once
class WarGame
{

private:
	int counter;

public:
	Deck mainDeck;
	Player computer;
	Player human;
	Deck *junkPile;

	WarGame();
	void setColour(int);
	void initializeWelcome();
	void displayWelcome(string, string);
	void displayCardPlayed(int);
	void compare(int);
	void displayHands();
	void startGame();
	void transferCards();
	void playGame();
	void displayRounds();
	void splitDeck();
	bool checkWinner();
	int checkGreatorCard();
	~WarGame();
};

