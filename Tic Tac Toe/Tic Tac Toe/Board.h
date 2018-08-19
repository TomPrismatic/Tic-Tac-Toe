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

	//Checks to see if the game is won or tied
	bool isBoardFull();
	int checkGameWinner();

	//Players Turn
	void playerTurn();

	//Minmax algorithm which returns a 2d vecor storing the correct move the algorithm must take
	std::vector<int> minMaxAlgorithm();

	//Funtion to maximise the score
	int maximise();

	//Funtion to minimise the score
	int minimise();
	

};

