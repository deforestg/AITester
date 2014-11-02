/*
 * Human.cpp
 *
 *  Created on: Nov 1, 2014
 *      Author: gdeforest
 */

#include "include/Human.h"

namespace TicTacToe {

	Human::Human(char symbol) : Player(symbol) {

	}

	void Human::Move(Board* board) {
		int x, y;

		do {
			cout << "X: ";
			cin >> x;
			cout << "Y: ";
			cin >> y;
		} while (!board->Move(x, y, symbol));
	}

	Human::~Human() {

	}

}
