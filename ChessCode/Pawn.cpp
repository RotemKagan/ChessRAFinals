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
	std::string dest = std::string(1, move[2]) + std::string(1, move[3]);
	std::string curr = std::string(1, move[0]) + std::string(1, move[1]);
	int startCol = move[0] - 'a';
	int startRow = move[1] - '1';
	int endCol = move[2] - 'a';
	int endRow = move[3] - '1';
	if (board.getPiece(curr)->getName() != "Pawn")
	{
		return 2;
	}
	if ((startCol < 1 || startCol>8) || (endCol < 1 || endCol>8))
	{
		return 5;
	}
	if ((startRow < 1 || startRow>8) || (endRow < 1 || endRow>8))
	{
		return 5;
	}
	int pColor = getColor(); // 0 = white 1 = black

	//checks if move is backwards 
	if (color == 0) {
		if (startRow < endRow) {
			return 6;
		}
	}
	else if (color == 1) {
		if (startRow > endRow) {
			return 6;
		}
	}


	//if same place
	if (startCol == endCol && startRow == endRow)
	{
		return 7;
	}

	dPiece = board.getPiece(dest);

	if (startCol == endCol) { //moving normaly
		if (dPiece) {
			return 6;
		}

		if (std::abs(startRow - endRow) == 2 && !hasMoved) {
			return 0;
		}

		if (std::abs(startRow - endRow) == 1) {
			return 0;
		}

		return 6;

	}
	else if (std::abs(startCol - endCol) == 1) { //if captured a piece
		if (std::abs(startRow - endCol) != 1) {
			return 6;
		}

		if (!dPiece) { //capturing empty place
			return 6;
		}

		if (dPiece->getColor() == pColor) { //trying to capture same colored piece
			return 3;
		}

		return 0;

	}
	else { // ilegal mive
		return 6;
	}

}

bool Pawn::isUnderCheck(std::string pos, Board board) {
	return false;
}