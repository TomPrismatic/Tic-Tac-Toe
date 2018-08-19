#include "Board.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;


enum gameBoardStates
{
	//defines the different states the board can be in
	emptySpace = '.',
	x = 'X',
	o = 'O'
};

//Creates a 3x3 array with type gameBoardStates
gameBoardStates gameBoard[3][3];

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
		//Clears window
		system("CLS");
		//sets the game to easy
		generateBoard();
		return;
	}

	if (playerInput == 'H')
	{
		//Clears window
		system("CLS");
		//Sets the game to hard
		generateBoard();
		return;
	}
}

void Board::generateBoard()
{
	//Creates the board, 3x3 array of empty Spaces
	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			gameBoard[i][j] = emptySpace;
		}
	}

	//Generated the game board
	cout << "____________________";
	for (unsigned int i = 0; i < 3; i++)
	{
		cout << "\n|";
		for (unsigned int j = 0; j < 3; j++)
		{
			cout << setw(3) << static_cast<char>(gameBoard[i][j]) << setw(3) << " |";
		}
	}
	cout << "\n____________________\n";

	char playerInput;
	cin >> playerInput;
}

bool Board::isBoardFull()
{
	//Checks each space in the board
	for (unsigned int i = 0; i < 3; i++)
	{
		//Checks too see if their is any space left on the board
		if (gameBoard[i][0] == emptySpace || gameBoard[i][1] == emptySpace || gameBoard[i][2] == emptySpace)
		{
			return false;
		}
			
	}
	//If the board is full then the game is a tie
	return true;
}

int Board::checkGameWinner()
{
	//will return an int, if 1 is returned then x won, if 2 is returned o has won.
	//If 0 is returned neither has won yet

	//Firstly check to see if x has won, if there are 3 in a row then game is over
	for (unsigned int i = 0; i < 3; i++)
	{
		// Check horizontal victory
		if (gameBoard[i][0] == x && gameBoard[i][1] == x && gameBoard[i][2] == x)
			return 1;

		// Check vertical victory
		if (gameBoard[0][i] == x && gameBoard[1][i] == x && gameBoard[2][i] == x)
			return 1;
	}

	// Check diagonals
	if (gameBoard[0][0] == x && gameBoard[1][1] == x && gameBoard[2][2] == x)
		return 1;

	if (gameBoard[0][2] == x && gameBoard[1][1] == x && gameBoard[2][0] == x)
		return 1;

	//Secondly check to see if o has won, if there are 3 in a row then game is over
	for (unsigned int i = 0; i < 3; i++)
	{
		// Check horizontal victory
		if (gameBoard[i][0] == o && gameBoard[i][1] == o && gameBoard[i][2] == o)
			return 2;

		// Check vertical victory
		if (gameBoard[0][i] == o && gameBoard[1][i] == o && gameBoard[2][i] == o)
			return 2;
	}

	// Check diagonals
	if (gameBoard[0][0] == o && gameBoard[1][1] == o && gameBoard[2][2] == o)
		return 2;

	if (gameBoard[0][2] == o && gameBoard[1][1] == o && gameBoard[2][0] == o)
		return 2;

	//if noone has won yet
	return 0;
}

void Board::playerTurn()
{
	bool fail = true;
	unsigned int playerMovementX = -1, playerMovementY = -1;

	while (fail == true)
	{
		std::cout << "Please enter where you wish to place your x: ";

		char playerInputX;
		std::cin >> playerInputX;
		playerMovementX = playerInputX - '0';

		char playerInputY;
		std::cin >> playerInputY;
		playerMovementY = playerInputY - '0';

		fail = gameBoard[playerMovementX][playerMovementY] != emptySpace;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}

	gameBoard[playerMovementX][playerMovementY] = x;
}

std::vector<int> Board::minMaxAlgorithm()
{
	//Creates a int Score which will be used to calculate the best move
	int score;
	//Creates a 2D vector which will hold the coordinates for the ai's move
	std::vector<int> correctMove = {0, 0};

	//Iterates through all spaces on the board
	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			//If the space on the board is still free
			if (gameBoard[i][j] == emptySpace)
			{
				//Set the space to o
				gameBoard[i][j] = o;

				//Calls the maximise funtion
				int minmaxTemp = maximise();

				//If the returned value is less than the current score
				if (minmaxTemp < score)
				{
					//Set the correctMove to this position
					score = minmaxTemp;
					correctMove[0] = i;
					correctMove[1] = j;
				}
				//Reset board to previous state
				gameBoard[i][j] = emptySpace;
			}
		}
	}

	return correctMove;
}

int Board::maximise()
{
	//Check to see if the player has won (1 is player)
	if (checkGameWinner() == 1) 
	{ 
		return 10;
	}

	//Check to see if the computer has won (2 is computer)
	else if (checkGameWinner() == 2)
	{
		return -10;
	}

	//Check to see if the board is now full
	else if (isBoardFull()) 
	{ 
		return 0; 
	}

	//otherwise score is the variable we will be returning
	int score;
	
	//Iterate through the board
	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			//If the space is currently empty
			if (gameBoard[i][j] == emptySpace)
			{
				//Set it to a space taken by the player
				gameBoard[i][j] = x;
				//Calls the minimise funtion, if the value returned is greater than the current score, this value is assigned to score
				score = max(score, minimise());
				//Return the game board to its previous state
				gameBoard[i][j] = emptySpace;
			}
		}
	}

	return score;
}

int Board::minimise()
{
	//Check to see if the player has won (1 is player)
	if (checkGameWinner() == 1)
	{
		return 10;
	}

	//Check to see if the computer has won (2 is computer)
	else if (checkGameWinner() == 2)
	{
		return -10;
	}

	//Check to see if the board is now full
	else if (isBoardFull())
	{
		return 0;
	}

	//otherwise score is the variable we will be returning
	int score;

	//Iterate through the board
	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			//If the space is currently empty
			if (gameBoard[i][j] == emptySpace)
			{
				//Set it to a space taken by the computer
				gameBoard[i][j] = o;
				//Calls the maximise funtion, if the value returned is less than the current score, this value is assigned to score
				score = min(score, maximise());
				//Return the game board to its previous state
				gameBoard[i][j] = emptySpace;
			}
		}
	}

	return score;
}
