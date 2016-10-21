#include "utility.h"



Utility::Utility()
{
}

Utility::~Utility()
{
}

void Utility::changeColour(int colourNum)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colourNum);
}