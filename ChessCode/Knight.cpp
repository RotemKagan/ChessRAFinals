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
    std::string dest = std::string(1, move[2]) + std::string(1, move[3]);
    std::string curr = std::string(1, move[0]) + std::string(1, move[1]);
    int startCol = move[0] - 'a';
    int startRow = move[1] - '1';
    int endCol = move[2] - 'a';
    int endRow = move[3] - '1';
    if (board.getPiece(curr)->getName() != "Knight")
    {
        return 2;
    }
    if ((startCol < 1 || startCol>8) || (endCol < 1 || endCol>8))
    {
        return 5;
    }
    if ((startRow < 1 || startRow>8) || (endRow < 1 || endRow>8))
    {
        return 5;
    }
    if (startRow == endRow && startCol == endCol)
    {
        return 7;
    }
    if (!((abs(startRow - endRow) == 1 && abs(startCol - endCol) == 2) || (abs(startRow - endRow) == 2 && abs(startCol - endCol )== 1)))
    {
        return 6;
    }
    Piece* target = board.getPiece(dest);
    if (target != nullptr && target->getColor() == this->getColor())
    {
        return 3;
    }
    return 0;
}
bool Knight::isUnderCheck(std::string pos, Board board) 
{
	return false;
}