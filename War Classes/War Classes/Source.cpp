#include <iostream>
#include <cstdlib>
#include "WarGame.h"
#include "Player.h"
#include "deck.h"

using namespace std;

int main()
{
	WarGame myWarGame;
	myWarGame.initializeWelcome();
	myWarGame.startGame();


	system("PAUSE");
	return 0;
}