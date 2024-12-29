#include "Pawn.h"
#include <iostream>
#include <cmath>

Pawn::Pawn(int color, std::string name): Piece(color, name) {
	hasMoved = 0;
}
Pawn::~Pawn() {
	hasMoved = 0;
}

void Pawn::makeMove(std::string move, Board board) {
	hasMoved = 1;
	board.makeMove(move);
}


int Pawn::isLegal(std::string move, Board board) {
	Piece* dPiece = NULL;
	//converting 
	std::string dest = move.substr(2, 2);
	int startCol = move[0] - 'a';
	int startRow = move[1] - '1';
	int endCol = move[2] - 'a';
	int endRow = move[3] - '1';

	int pColor = getColor(); // 0 = white 1 = black

	//checks if move is backwards 
	if (color == 0) {
		if (startRow < endRow) {
			return false;
		}
	}
	else if (color == 1) {
		if (startRow > endRow) {
			return false;
		}
	}


	//if same place
	if (startCol == endCol && startRow == endRow)
	{
		return false;
	}

	dPiece = board.getPiece(dest);

	if (startCol == endCol) { //moving normaly
		if (dPiece) {
			return false;
		}

		if (std::abs(startRow - endRow) == 2 && !hasMoved) {
			return true;
		}

		if (std::abs(startRow - endRow) == 1) {
			return true;
		}

		return false;

	}
	else if (std::abs(startCol - endCol) == 1) { //if captured a piece
		if (std::abs(startRow - endCol) != 1) {
			return false;
		}

		if (!dPiece) { //capturing empty place
			return false;
		}

		if (dPiece->getColor() == pColor) { //trying to capture same colored piece
			return false;
		}

		return true;

	}
	else { // ilegal mive
		return false;
	}

}

bool Pawn::isUnderCheck(std::string pos, Board board) {
	return false;
}