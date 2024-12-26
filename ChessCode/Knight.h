#pragma once
#include "Board.h"
#include "Piece.h"
class Knight: public Piece
{

public:
	Knight(int color, std::string name);
	~Knight();
	virtual void makeMove(std::string move, Board board) override;
	virtual bool isLegal(std::string move, Board board) override;
	virtual bool isUnderCheck(std::string pos, Board board) override;
};
