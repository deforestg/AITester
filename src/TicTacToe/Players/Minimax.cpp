/*
 * Minimax.cpp
 *
 *  Created on: Nov 10, 2014
 *      Author: gdeforest
 */

#include "include/Minimax.h"

namespace TicTacToe {

	Minimax::Minimax(char symbol, char opponent, int depth) : Player(symbol) {
		this->opponent = opponent;
		this->depth = depth;
		sizeX = sizeY = moveX = moveY = winLength = 0;
	}

	void Minimax::Move(Board* board) {
		sizeX = board->GetSizeX();
		sizeY = board->GetSizeY();
		winLength = board->GetWinLength();

		moveX = moveY = -1;
		int currentDepth = depth;
		if (board->GetSpacesLeft() < depth) {
			currentDepth = board->GetSpacesLeft();
		}
		minimax(board, currentDepth);

		board->Move(moveX, moveY, symbol);
	}

	int Minimax::minimax(Board* board, int depth, bool maximizing, bool firstRun) {
		int value = boardValue(board);
		if (value || !depth) {	// if game ending move or out of depth
			return value;
		}
		int best;
		Board* newBoard;

		if (maximizing) {
			best = INT_MIN;
			for (int i = 0; i < sizeY; i++) {
				for (int j = 0; j < sizeX; j++) {
					if (board->Get(j, i)) {
						continue;
					}
					newBoard = board->Clone();
					newBoard->Move(j, i, symbol);

					int current = minimax(newBoard, depth - 1, false, false);
					if (current >= best) {
						best = current;

						if (firstRun) {
							moveX = j;
							moveY = i;
						}
					}
				}
			}
		} else {
			best = INT_MAX;
			for (int i = 0; i < sizeY; i++) {
				for (int j = 0; j < sizeX; j++) {
					if (board->Get(j, i)) {
						continue;
					}
					newBoard = board->Clone();
					newBoard->Move(j, i, opponent);

					best = min(best, minimax(newBoard, depth - 1, true, false));
				}
			}
		}

		return best;
	}

	/**
	 * for now no heuristic, just W/L
	 */
	int Minimax::boardValue(Board* board) {
		char winner = board->FindWinner();

		if (winner == symbol) {
			return INT_MAX;
		} else if (winner == opponent) {
			return INT_MIN;
		}

		return 0;
	}

	Minimax::~Minimax() {

	}

}
