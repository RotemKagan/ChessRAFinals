#include "Knight.h"
Knight::Knight(int color, std::string name)
	:Piece(color,name)
{
}
Knight::~Knight() 
{
}
void Knight::makeMove(std::string move, Board board) 
{
	board.makeMove(move);
}
int Knight::isLegal(std::string move, Board board)
{
    std::string dest = move.substr(2, 2);
    //converts
    int currRow = move[1] - '1';
    int currCol = move[0] - 'a';
    int destRow = move[3] - '1';
    int destCol = move[2] - 'a';
    //moving to same place
    if (currRow == destRow && currCol == destCol)
    {
        return false;
    }
    if (!((abs(currRow - destRow) == 1 && abs(currCol - destCol) == 2) || (abs(currRow - destRow) == 2 && abs(currCol - destCol )== 1)))
    {
        return false;
    }
    Piece* target = board.getPiece(dest);
    if (target != nullptr && target->getColor() == this->getColor())
    {
        return false;
    }
    return true;
}
bool Knight::isUnderCheck(std::string pos, Board board) 
{
	return false;
}