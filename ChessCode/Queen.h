#pragma once
#include "Board.h"
#include "Piece.h"
class Queen : public Piece
{

public:
	Queen(int color, std::string name);
	~Queen();
	virtual void makeMove(std::string move, Board board) override;
	virtual int isLegal(std::string move, Board board) override;
	virtual bool isUnderCheck(std::string pos, Board board) override;
};
