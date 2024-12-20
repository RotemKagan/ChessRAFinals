#pragma once
#include "Board.h"
#include "Piece.h"
class Rook : public Piece
{

public:
	Rook(int color, std::string name);
	~Rook();
	virtual void makeMove(std::string move, Board board) override;
	virtual bool isLegal(std::string move, Board board) override;
	virtual bool isDoCheck(Board board) override;
};
