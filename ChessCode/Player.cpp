#include "Player.h"
#include <iostream>

Player::Player(int _color) 
{
	color = _color;
}

Player::~Player() 
{
	color = 0;
}

int Player::getColor()const 
{
	return color;
}

void Player::setKing(Piece* _king) 
{
	king = _king;
}
Piece* Player::getKing()const 
{
	return king;
}
std::string Player::KingPoistionOfPlayer(Board board)
{
	for (char j = 'a'; j <= 'z'; j++)
	{
		for (int i =1;i<=8;i++) 
		{
			std::string position = std::string(1, i) + std::to_string(j);
			Piece* piece = board.getPiece(position);
			if (piece && piece->getName() == "King" && piece->getColor() == this->color)
			{
				return position;
			}
		}
	}
}