#pragma once
#include "Piece.h"
#include "Board.h"

class Player {
private:
	int color; //0 White - 0 Black

public:
	Player(int _color);
	~Player();
	int getColor()const;
};