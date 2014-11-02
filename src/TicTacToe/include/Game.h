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
			Player** players;
			int numPlayers;
			Board* board;
			void init(Player** players, int numPlayers, Board* board);
		public:
			/* a bunch of different ways to initialize a game */
			Game(Player** players, int numPlayers);
			Game(Player** players, int numPlayers, int sizeX, int sizeY, int winLength = 0);
			Game(Player** players, int numPlayers, Board* board);
			void Reset();
			void Start();
	};

}

#endif /* GAME_H_ */
