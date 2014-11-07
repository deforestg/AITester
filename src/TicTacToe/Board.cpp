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
	Board::Board(int sizeX, int sizeY, int winLength) {
		this->sizeX = sizeX;
		this->sizeY = sizeY;

		board = new char*[sizeY];
		for (int i = 0; i < sizeY; i++) {
			board[i] = new char[sizeX];
		}

		spacesLeft = sizeX * sizeY;

		if (winLength > 0) {
			this->winLength = winLength;
		} else {
			// keep the game interesting: 3x3 is 3, 4x4 is 4, 5x5 is 4
			this->winLength = round((sizeX + sizeY)/2 * 0.89);
		}

		verticalSeparater = " | ";
		char* temp = new char[sizeX * (int)verticalSeparater.length()];
		memset(temp, '-', sizeX * (int)verticalSeparater.length());
		horizontalSeparater = temp;
	}

	/**
	 * attempt to make a move
	 * @param int x
	 * @param int y
	 * @param char player
	 * @return bool - success/fail
	 */
	bool Board::Move(int x, int y, char player) {
		if (x >= sizeX || x < 0 || y >= sizeY || y < 0 || board[y][x]) {
			cout << "invalid move" << endl;
			return 0;
		}

		board[y][x] = player;
		spacesLeft--;
		return 1;
	}

	/**
	 * @return char: -1 is no spaces left, 0 for no winner, or char player who won
	 */
	char Board::FindWinner() {

		if (!spacesLeft) {
			return -1;
		}

		int i, j, inARow = 1;
		char previous = 0;

		// scan horizontallly
		for (i = 0; i < sizeY; i++) {
			for (j = 0; j < sizeX; j++) {
				if (previous && board[i][j] == previous) {
					inARow++;
				} else {
					inARow = 1;
				}

				if (inARow == winLength) {
					return previous;
				}
				previous = board[i][j];
			}

			inARow = 0;
		}

		// scan vertically
		for (j = 0; j < sizeX; j++) {
			for (i = 0; i < sizeY; i++) {
				if (previous && board[i][j] == previous) {
					inARow++;
				} else {
					inARow = 1;
				}

				if (inARow == winLength) {
					return previous;
				}
				previous = board[i][j];
			}

			inARow = 1;
		}

		int temp;
		// scan diagonal top half
		for (j = 0; j < sizeX; j++) {
			temp = j;
			for (i = 0; i < sizeY && temp < sizeX; i++, temp++) {
				if (previous && board[i][temp] == previous) {
					inARow++;
				} else {
					inARow = 1;
				}

				if (inARow == winLength) {
					return previous;
				}
				previous = board[i][temp];
			}

			inARow = 1;
		}
		// scan diagonal bottom half
		for (i = 1; i < sizeY; i++) {
			temp = i;
			for (j = 0; j < sizeX && temp < sizeY; j++, temp++) {
				if (previous && board[temp][j] == previous) {
					inARow++;
				} else {
					inARow = 1;
				}

				if (inARow == winLength) {
					return previous;
				}
				previous = board[temp][j];
			}

			inARow = 1;
		}

		// scan reverse diagonal top half
		for (j = sizeX-1; j >= 0; j--) {
			temp = j;
			for (i = 0; i < sizeY && temp >= 0; i++, temp--) {
				if (previous && board[i][temp] == previous) {
					inARow++;
				} else {
					inARow = 1;
				}

				if (inARow == winLength) {
					return previous;
				}
				previous = board[i][temp];
			}

			inARow = 1;
		}
		// scan reverse diagonal bottom half
		for (i = 1; i < sizeY; i++) {
			temp = i;
			for (j = sizeX-1; j >= 0 && temp < sizeY; j--, temp++) {
				if (previous && board[temp][j] == previous) {
					inARow++;
				} else {
					inARow = 1;
				}

				if (inARow == winLength) {
					return previous;
				}
				previous = board[temp][j];
			}

			inARow = 1;
		}

		return 0;
	}

	/**
	 * @param int x
	 * @param int y
	 * @return char at position x, y
	 */
	char Board::Get(int x, int y) {
		return board[y][x];
	}

	/**
	 * prints the board to standard output
	 */
	void Board::Print() {
		cout << endl;

		for (int i = 0; i < sizeY; i++) {
			if (i) {	//don't on first
				cout << horizontalSeparater << endl;
			}

			for (int j = 0; j < sizeX; j++) {
				char output = board[i][j] ?: ' ';

				if (j > 0) {
					cout << verticalSeparater;
				}

				cout << output;
			}

			cout << endl;
		}
		cout << endl;
	}

	/**
	 * set all spaces to 0
	 */
	void Board::Reset() {
		for (int i = 0; i < sizeY; i++) {
			for (int j = 0; j < sizeX; j++) {
				board[i][j] = 0;
			}
		}

		spacesLeft = sizeX * sizeY;
	}

	Board::~Board() {
		delete[] board;
	}

}
