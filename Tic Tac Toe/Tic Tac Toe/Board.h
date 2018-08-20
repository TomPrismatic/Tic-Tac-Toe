#pragma once
#include <vector>

class Board
{
public:
	Board();
	~Board();

	//Generate the title screen and board
	void generateMenu();
	void generateBoard();

	//Cout the current Board State
	void displayBoard();

	//Game loop for the Easy mode
	void gamePlayEasy();
	//Game loop for the Hard mode
	void gamePlayHard();
	//Game loop for the PVP mode
	void gamePlayPVP();

	//Randomly selects two values and tries to place a o there
	std::vector<int> easyRandomPlacement();

	//Checks to see if the game is won or tied
	bool isBoardFull();
	int checkGameWinner();

	//Players Turn
	void playerTurn();

	//When in PVP, player 2's Turn
	void player2Turn();

	//Minmax algorithm which returns a 2d vecor storing the correct move the algorithm must take
	std::vector<int> minMaxAlgorithm();

	//Funtion to maximise the score
	int maximise();

	//Funtion to minimise the score
	int minimise();
	

};

