#include "Board.h"
#include <iostream>

using namespace std;

Board* gameBoard;

int main()
{
	gameBoard = new Board();
	gameBoard->generateMenu();
}