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

	int x, y, w;
	cout << "Enter board size x: ";
	cin >> x;
	cout << endl << "Enter board size y: ";
	cin >> y;
	cout << endl << "Enter win length: ";
	cin >> w;

	int numPlayers = 2;
	Player** players = new Player*[numPlayers];
	players[0] = new Human('x');
	players[1] = new Human('o');

	Game* game = new Game(players, numPlayers, x, y, w);
	game->Start();

	return 0;
}
