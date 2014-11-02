/*
 * Human.h
 *
 *  Created on: Nov 1, 2014
 *      Author: gdeforest
 */

#ifndef HUMAN_H_
#define HUMAN_H_

#include "Player.h"
#include <iostream>

using namespace std;

namespace TicTacToe {

	class Human : public Player {
		public:
			Human(char symbol);
			void Move(Board* board);
			virtual ~Human();
	};

}

#endif /* HUMAN_H_ */
