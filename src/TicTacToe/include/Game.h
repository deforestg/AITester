/*
 * Game.h
 *
 *  Created on: Nov 1, 2014
 *      Author: gdeforest
 */

#ifndef GAME_H_
#define GAME_H_

#include "Board.h"
#include "../Players/include/Player.h"

namespace TicTacToe {

	class Game {
		protected:
			Board* board;
			Player** players;
		public:
			/* a bunch of different ways to initialize a game */
			Game(Player** players);
			Game(Player** players, int sizeX, int sizeY);
			Game(Player** players, Board* board);
			void New();
	};

}

#endif /* GAME_H_ */