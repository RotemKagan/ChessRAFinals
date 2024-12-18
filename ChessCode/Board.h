#ifndef BOARD_H
#define BOARD_H

#define WIDTH 8
#define HEIGHT 8

#include <iostream>
#include <vector>
#include "Piece.h"

class Board {
private:
	std::vector<std::vector<Piece*>> board;
public:
	Board();

	void clearBoard();
	void resetBoard();
	void makeMove(std::string move);
	bool isCheck();

	Piece* getPiece(std::string pos);
};


#endif