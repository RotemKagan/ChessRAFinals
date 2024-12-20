#include "Piece.h"
Piece::Piece(int color, std::string name) 
{
	this->color = color;
	this->name = name;
}
Piece::~Piece() 
{
	this->name = "";
}
std::string Piece::getName()const 
{
	return this->name;
}
int Piece::getColor()const 
{
	return this->color;
}