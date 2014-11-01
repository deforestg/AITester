/*
 * Board.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: gdeforest
 */

#include "include/Board.h"


namespace TicTacToe {

	/**
	 * makes a custom board size
	 * @param int sizeX
	 * @param int sizeY
	 */
	Board::Board(int sizeX, int sizeY) {
		this->sizeX = sizeX;
		this->sizeY = sizeY;
		sizeTotal = sizeX * sizeY;
		board = new char[sizeTotal];

		separater = new char[sizeX];
		for (int i = 0; i < sizeX; i++) {
			separater[i] = '-';
		}
	}

	/**
	 * attempt to make a move
	 * @param int x
	 * @param int y
	 * @param char player
	 * @return bool - success/fail
	 */
	bool Board::Move(int x, int y, char player) {
		int translated = x + (y * sizeY);
		if (board[translated]) {
			return 0;
		}

		board[translated] = player;
		return 1;
	}

	/**
	 * prints the board to standard output
	 */
	void Board::Print() {
		for (int i = 0; i < sizeTotal; i++) {
			if (i % sizeX == 0) {
				cout << separater;
			} else if ((i + 1) % sizeX == 0) {
				cout << board[i];
			}
			cout << board[i] << " | ";
		}
	}

	Board::~Board() {
		delete[] board;
		delete[] separater;
	}

}
