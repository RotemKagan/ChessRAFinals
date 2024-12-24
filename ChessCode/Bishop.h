#pragma once
#include "Board.h"
#include "Piece.h"
class Bishop : public Piece
{

public:
	Bishop(int color, std::string name);
	~Bishop();
	virtual void makeMove(std::string move, Board board) override;
	virtual bool isLegal(std::string move, Board board) override;
	virtual bool isUnderCheck(std::string pos, Board board) override;
};
