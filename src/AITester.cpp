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
	int numPlayers = 2;
	Player** players = new Player*[numPlayers];
	players[0] = new Human('x');
	players[1] = new Human('o');

	Board* board = new Board("../saved/game1.ttt");

	Game* game = new Game(players, numPlayers, board);
	game->Start();

	return 0;
}
