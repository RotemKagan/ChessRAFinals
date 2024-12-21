#include "Board.h"
#include "Piece.h"
#include "King.h"
//check my code and correct if needed
King::King(int color, std::string name)
	:Piece(color, name)
{

}
King::~King()
{

}
void King::makeMove(std::string move, Board board)
{
	board.makeMove(move);
}
bool King::isLegal(std::string move, Board board)
{

    char startCol = move[0]-'a';
    int startRow = move[1] - '1';
    char endCol = move[2]-'a';
    int endRow = move[3] - '1'; 

    // didnt move 
    if (startCol == endCol && startRow == endRow)
    {
        return false;
    }
    int destX = endRow;
    int destY = endCol - 'a';

    // Check if move is one square in any direction
    if (abs(endRow - startRow) <= 1 && abs(endCol - startCol) <= 1)
    {
        Piece* targetPiece = board.getPiece(move.substr(2, 2)); 
        if (targetPiece == nullptr || targetPiece->getColor() != this->getColor())
        {
            return true; 
        }
    }

    return false; 
}
//now all the check stuff and moving the king if needed and all that with the check try to do please