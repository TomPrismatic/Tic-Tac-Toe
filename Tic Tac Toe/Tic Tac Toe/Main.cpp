#include "Board.h"
#include <iostream>
#include "Easy.h"

using namespace std;

Board* gameBoard;

int main()
{
	gameBoard = new Board();
	gameBoard->generateMenu();
}