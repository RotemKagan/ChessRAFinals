#pragma once
#include "Piece.h"
#include "Board.h"
#include "King.h"

class Player {
private:
	int color; //0 White - 0 Black
	Piece* king; //so we can know if the king has beem captured/ its a piece pointer because of board
public:
	Player(int _color);
	~Player();
	int getColor()const;
	void setKing(Piece* _king);
	Piece* getKing()const;
};