#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include "Board.h"

class Board;

class Piece {
protected: 
	int color; //0 = white - 1 = black
	std::string name;
public:
	Piece(int color, std::string name);
	~Piece();
	virtual void makeMove(std::string move, Board board) = 0;
	virtual bool isLegal(std::string move, Board board) = 0;
	std::string getName()const;
	int getColor()const;
	virtual bool isUnderCheck(std::string pos, Board board) = 0; //checks if king under check. if not a king it will return false. had to be virtual.
};



#endif