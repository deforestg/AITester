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
#include <stdio.h>

using namespace std;

namespace TicTacToe {

	class Board {
		protected:
			int sizeX;
			int sizeY;
			int winLength;
			int spacesLeft;
			string verticalSeparater; // for display
			string horizontalSeparater;
			// 2d array [sizeY][sizeX]
			char** board;
			void initBoard();
			void genWinLength();
			void genSeparators();
		public:
			Board(int sizeX = DEFAULT_BOARD_SIZE, int sizeY = DEFAULT_BOARD_SIZE, int winLength = 0);
			Board(const char* filename);
		    virtual Board* Clone();
			virtual ~Board();

			bool Move(int x, int y, char player);
			char FindWinner();
			void Print();
			void Reset();
			void Load(const char* filename);
			void Save(const char* filename);

			char** GetBoard() { return board; };
			char Get(int x, int y);
			int GetSizeX() { return sizeX; }
			int GetSizeY() { return sizeY; }
			int GetWinLength() { return winLength; }
	};

}

#endif /* BOARD_H_ */
