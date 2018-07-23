#include "Board.h"
#include <iostream>

using namespace std;



Board::Board()
{
}


Board::~Board()
{
}

void Board::generateMenu()
{
	//Cout the menu
	cout << "  _____________________________  " << endl;
	cout << "||                             ||" << endl;
	cout << "||Welcome to Tom's Tic Tac Toe!||" << endl;
	cout << "||                             ||" << endl;
	cout << "||   Choose Your Difficulty!   ||" << endl;
	cout << "||     Type 'E' for Easy!      ||" << endl;
	cout << "||       Or if you want        ||" << endl;
	cout << "||      a real challenge       ||" << endl;
	cout << "||          TYPE H...          ||" << endl;
	cout << "||_____________________________||" << endl;

	//Gets player input for difficulty
	char playerInput;
	cin >> playerInput;

	if (playerInput == 'E')
	{
		//sets the game to easy
		generateBoard(false);
		return;
	}

	if (playerInput == 'H')
	{
		//Sets the game to hard
		generateBoard(true);
		return;
	}
}

void Board::generateBoard(bool isHard)
{
	//if the game is easy mode
	if (isHard == false)
	{

	}
}
