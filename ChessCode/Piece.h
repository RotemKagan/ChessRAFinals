#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include "Board.h"

class Piece {
protected: 
	int color;
	std::string name;
public:
	Piece(int color, std::string name);

	virtual void makeMove(std::string move, Board board) = 0;
	virtual bool isLegal(std::string move, Board board) = 0;
	virtual bool isDoCheck(Board board) = 0; //func checks if this piece is threatening the king, returns true if it is
};



#endif