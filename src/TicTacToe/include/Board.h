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

using namespace std;

namespace TicTacToe {

	class Board {
		protected:
			int sizeX;
			int sizeY;
			int sizeTotal;
			char* separater; // for display
			// one continuous array of sizeX*sizeY
			char* board;
		public:
			Board(int sizeX = DEFAULT_BOARD_SIZE, int sizeY = DEFAULT_BOARD_SIZE);
			bool Move(int x, int y, char player);
			char* GetBoard() { return board; };
			void Print();
			virtual ~Board();
	};

}

#endif /* BOARD_H_ */
