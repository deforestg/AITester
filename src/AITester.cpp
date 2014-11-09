//============================================================================
// Name        : AITester.cpp
// Author      : Gabriel de Forest
// Version     :
// Copyright   : No copyright
// Description : Tests AI
//============================================================================

#include "TicTacToe/include/Game.h"
#include "TicTacToe/Players/include/Human.h"

using namespace TicTacToe;

int main(int argc, char** argv) {

//	o | o | x | o
//	------------
//	o |   | x |
//	------------
//	o |   | x | x
//	------------
//	x | x |   |


//	Board* board = new Board(4, 4);
//	board->Move(0, 0, 'o');
//	board->Move(1, 0, 'o');
//	board->Move(2, 0, 'x');
//	board->Move(3, 0, 'o');
//	board->Move(0, 1, 'o');
//	board->Move(2, 1, 'x');
//	board->Move(0, 2, 'o');
//	board->Move(2, 2, 'x');
//	board->Move(3, 2, 'x');
//	board->Move(0, 3, 'x');
//	board->Move(1, 3, 'x');
//
//	board->Save("../saved/game1.ttt");

	int numPlayers = 2;
	Player** players = new Player*[numPlayers];
	players[0] = new Human('x');
	players[1] = new Human('o');

	Board* board = new Board("../saved/game1.ttt");

	Game* game = new Game(players, numPlayers, board);
	game->Start();

	return 0;
}
