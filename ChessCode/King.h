#pragma once
#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Board.h"

class Board;

class King : public Piece
{

public:
	King(int color, std::string name);
	~King();
	virtual void makeMove(std::string move, Board board) override;
	virtual int isLegal(std::string move, Board board) override;
	virtual bool isUnderCheck(std::string pos, Board board) override;
};
/*
class King : public Piece
{

public:
	King(int color, std::string name);
	~King();
	virtual void makeMove(std::string move, Board board) override;
	virtual int isLegal(std::string move, Board board) override;
	virtual bool isUnderCheck(std::string pos, Board board) override;
};*/

#endif

