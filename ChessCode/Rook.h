#pragma once
#include "Board.h"
#include "Piece.h"
class Rook : public Piece
{

public:
	Rook(int color, std::string name);
	~Rook();
	virtual void makeMove(std::string move, Board board) override;
	virtual int isLegal(std::string move, Board board) override;
	virtual bool isUnderCheck(std::string pos, Board board) override;
};
