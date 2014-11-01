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
	 */
	Game::Game(Player** players) {
		init(players, new Board());
	}

	/**
	 * initializes a game providing the desired board size
	 * @param Player** players
	 * @param int sizeX
	 * @param int sizeY
	 * @param int winLength
	 */
	Game::Game(Player** players, int sizeX, int sizeY, int winLength) {
		init(players, new Board(sizeX, sizeY, winLength));
	}

	/**
	 * initializes a game with an existing board
	 * @param Player** players
	 * @param Board* board
	 */
	Game::Game(Player** players, Board* board) {
		init(players, board);
	}

	/**
	 * initialization helper function
	 * @param Player** players
	 * @param Board* board
	 */
	void Game::init(Player** players, Board* board) {
		this->players = players;
		this->board = board;
	}
}
