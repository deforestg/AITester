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

using namespace std;

namespace TicTacToe {

	class Board {
		protected:
			int sizeX;
			int sizeY;
			int sizeTotal;
			int winLength;
			string verticalSeparater; // for display
			string horizontalSeparater;
			// one continuous array of sizeX*sizeY
			char* board;
		public:
			Board(int sizeX = DEFAULT_BOARD_SIZE, int sizeY = DEFAULT_BOARD_SIZE, int winLength = 0);
			bool Move(int x, int y, char player);
			char FindWinner();
			char* GetBoard() { return board; };
			void Print();
			void Reset();
			virtual ~Board();
	};

}

#endif /* BOARD_H_ */
