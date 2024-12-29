#pragma once
#include "Board.h"
#include "Piece.h"
class King : public Piece
{

public:
	King(int color, std::string name);
	~King();
	virtual void makeMove(std::string move, Board board) override;
	virtual int isLegal(std::string move, Board board) override;
	virtual bool isUnderCheck(std::string pos, Board board) override;
};