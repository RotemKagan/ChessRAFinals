#include "Board.h"
#include "Piece.h"
#include "Rook.h"
Rook::Rook(int color, std::string name)
	:Piece(color, name)
{

}
Rook::~Rook() 
{

}
void Rook::makeMove(std::string move, Board board) 
{

}
bool Rook::isLegal(std::string move, Board board) 
{
	std::string curr = "";
	curr=move[0] + move[1];
	std::string dest = "";
	dest = move[2] + move[3];
	if (curr == dest) 
	{
		return false;
	}
	else if()
}