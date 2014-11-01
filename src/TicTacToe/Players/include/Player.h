/*
 * Player.h
 *
 *  Created on: Oct 28, 2014
 *      Author: gdeforest
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "../../include/Board.h"

namespace TicTacToe {

	class Player {
		private:
			Player();
			~Player();
		protected:
			char symbol;
		public:
			virtual void Move(Board* board) = 0;
	};

}

#endif /* PLAYER_H_ */
