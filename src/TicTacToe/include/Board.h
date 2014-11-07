/*
 * Board.h
 *
 *  Created on: Oct 28, 2014
 *      Author: gdeforest
 */

#ifndef BOARD_H_
#define BOARD_H_

#define DEFAULT_BOARD_SIZE 3

#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

namespace TicTacToe {

	class Board {
		protected:
			int sizeX;
			int sizeY;
			int winLength;
			int spacesLeft; // saves an x y loop
			string verticalSeparater; // for display
			string horizontalSeparater;
			// 2d array [sizeX][sizeY]
			char** board;
		public:
			Board(int sizeX = DEFAULT_BOARD_SIZE, int sizeY = DEFAULT_BOARD_SIZE, int winLength = 0);
			bool Move(int x, int y, char player);
			char FindWinner();
			char** GetBoard() { return board; };
			char Get(int x, int y);
			void Print();
			void Reset();
			virtual ~Board();
	};

}

#endif /* BOARD_H_ */
