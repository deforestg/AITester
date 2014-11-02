/*
 * Game.cpp
 *
 *  Created on: Nov 1, 2014
 *      Author: gdeforest
 */

#include "include/Game.h"

namespace TicTacToe {

	/**
	 * initializes a default game
	 * @param Player** players
	 * @param int numPlayers
	 */
	Game::Game(Player** players, int numPlayers) {
		init(players, numPlayers, new Board());
	}

	/**
	 * initializes a game providing the desired board size
	 * @param Player** players
	 * @param int numPlayers
	 * @param int sizeX
	 * @param int sizeY
	 * @param int winLength
	 */
	Game::Game(Player** players, int numPlayers, int sizeX, int sizeY, int winLength) {
		init(players, numPlayers, new Board(sizeX, sizeY, winLength));
	}

	/**
	 * initializes a game with an existing board
	 * @param Player** players
	 * @param int numPlayers
	 * @param Board* board
	 */
	Game::Game(Player** players, int numPlayers, Board* board) {
		init(players, numPlayers, board);
	}

	/**
	 * initialization helper function
	 * @param Player** players
	 * @param int numPlayers
	 * @param Board* board
	 */
	void Game::init(Player** players, int numPlayers, Board* board) {
		this->players = players;
		this->numPlayers = numPlayers;
		this->board = board;
	}

	/**
	 * reset game
	 */
	void Game::Reset() {
		board->Reset();
	}

	/**
	 * start game
	 */
	void Game::Start() {

		char winner;
		int count = 0;

		do {
			board->Print();

			players[count++]->Move(board);
			cout << endl;
			if (count >= numPlayers) {
				count = 0;
			}

			winner = board->FindWinner();
		} while(!winner);

		cout << "Winner: " << winner;
	}
}
