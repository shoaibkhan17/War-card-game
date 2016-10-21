#include "WarGame.h"



WarGame::WarGame()
{
	counter = 1;
	junkPile = new Deck;
}

void WarGame::initializeWelcome()
{
	system("COLOR F1");
	displayWelcome("WELCOME TO WAR GAME v1.0", "\n\n\n\n\n\n\n\n\n\n\n    \t\t\t");
	Utility::changeColour(7);
	Sleep(1200);
	system("CLS");
}

void WarGame::displayWelcome(string letter, string spacing)
{
	cout << spacing;

	for (auto character : letter)
	{
		cout << character;
		Sleep(50);
	}

	cout << endl;
}

void WarGame::setColour(int colourNum)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colourNum);
}

bool WarGame::checkWinner()
{
	if (human.hand->getTop() == -1)
	{
		computer.win = true;
		return true;
	}

	else if (computer.hand->getTop() == -1)
	{
		human.win = true;
		return true;
	}

	else
	{
		return false;
	}
}

void WarGame::displayCardPlayed(int position)
{
	setColour(15);
	cout << "You Played:      ";
	human.hand->getCard(position)->displayCardWithColour();

	setColour(15);
	cout << "Computer Played: ";
	computer.hand->getCard(position)->displayCardWithColour();
	setColour(14);
}

void WarGame::compare(int position)
{
	if ((human.hand->getTop() > -1) && (computer.hand->getTop() > -1))
	{
		displayCardPlayed(position);

		if (human.hand->getCard(position)->getRank() > computer.hand->getCard(position)->getRank())
		{
			cout << "-----> You Win <-----" << endl << endl;
			human.score++;
			human.hand->dealCard(human.SpareHand);
			computer.hand->dealCard(junkPile);
		}

		else if (human.hand->getCard(position)->getRank() < computer.hand->getCard(position)->getRank())
		{
			cout << "-----> You Lose <-----" << endl << endl;
			computer.score++;
			computer.hand->dealCard(computer.SpareHand);
			human.hand->dealCard(junkPile);
		}

		else if (human.hand->getCard(position)->getRank() == computer.hand->getCard(position)->getRank())
		{
			cout << "-----> WAR <-----" << endl << endl;
			computer.hand->dealCard(junkPile);
			human.hand->dealCard(junkPile);
		}
	}

	setColour(7);
}

int WarGame::checkGreatorCard()
{
	int cardNumber = 0;

	if (human.hand->getTop() == computer.hand->getTop())
	{
		cardNumber = human.hand->getTop();
	}

	else if (human.hand->getTop() > computer.hand->getTop())
	{
		cardNumber = computer.hand->getTop();
	}

	else if (human.hand->getTop() < computer.hand->getTop())
	{
		cardNumber = human.hand->getTop();
	}

	return cardNumber;
}

void WarGame::transferCards()
{
	for (int i = 0; i < human.score; i++)
	{
		human.SpareHand->dealCard(human.hand);
	}

	for (int i = 0; i < computer.score; i++)
	{
		computer.SpareHand->dealCard(computer.hand);
	}
}

void WarGame::displayHands()
{
	setColour(10);
	cout << "--> Human Hand <--" << endl;
	setColour(11);
	human.hand->displayDeckWithColour(true);

	setColour(10);
	cout << "\n--> Computer Hand <--" << endl;
	setColour(11);
	computer.hand->displayDeckWithColour(true);
	cout << endl;
}

void WarGame::playGame()
{
	human.score = computer.score = 0;

	for (int i = checkGreatorCard() ; i >= 0; i--)
	{
		displayRounds();
		compare(i);
		system("PAUSE");
		system("CLS");
	}

	transferCards();
}

void WarGame::displayRounds()
{
	setColour(10);
	cout << "-----> Round " << counter << " <-----" << endl;
	setColour(11);
	cout << "Your remaining card(s): " << human.hand->getTop() + 1 << endl;
	cout << "Computer's remaining card(s): " << computer.hand->getTop() + 1 << endl << endl;
	setColour(7);
}

void WarGame::startGame()
{
	mainDeck.initializeDeck();
	mainDeck.initializeColour();
	mainDeck.shuffleDeck();
	splitDeck();


	while (checkWinner() == false)
	{
		playGame();
		counter++;

		if (checkWinner() == true)
		{
			displayRounds();
			setColour(10);
			if (computer.win == true)
			{
				cout << endl << "-----> YOU LOST <-----" << endl << endl;
			}

			else
			{
				cout  << endl << "-----> YOU WON <-----" << endl << endl;
			}

			Sleep(450);
		}

		else
		{
			human.hand->shuffleDeck();
			computer.hand->shuffleDeck();
		}

		setColour(7);
		system("PAUSE");
		system("CLS");
	}	
}

void WarGame::splitDeck()
{
	for (int i = 0; i < 26; i++)
	{
		mainDeck.dealCard(human.hand);
		mainDeck.dealCard(computer.hand);
	}
}

WarGame::~WarGame()
{
}
