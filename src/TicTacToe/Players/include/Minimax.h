/*
 * Minimax.h
 *
 *  Created on: Nov 10, 2014
 *      Author: gdeforest
 */

#ifndef MINIMAX_H_
#define MINIMAX_H_

#include "Player.h"
#include <limits.h>

#define DEFAULT_DEPTH 9

namespace TicTacToe {

	class Minimax : public Player {
		private:
			int sizeX, sizeY;
			int moveX, moveY;
			int winLength;
			int depth;
			int minimax(Board* board, int depth, bool maximizing = true, bool firstRun = true);
			int boardValue(Board* board);
			char opponent;
		public:
			virtual ~Minimax();
			void Move(Board* board);
			Minimax(char symbol, char opponent, int depth = DEFAULT_DEPTH);
	};

}

#endif /* MINIMAX_H_ */
