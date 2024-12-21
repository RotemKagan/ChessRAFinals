#include "Board.h"
#include "Piece.h"
#include "Rook.h"
//check my code and correct if needed
Rook::Rook(int color, std::string name)
	:Piece(color, name)
{

}
Rook::~Rook() 
{

}
void Rook::makeMove(std::string move, Board board) 
{
    board.makeMove(move);
}
bool Rook::isLegal(std::string move, Board board) 
{
    std::string curr = "";
    std::string dest = "";
    dest = move[2] + move[3];
    curr = move[0] + move[1];
    //converts
    int currRow = curr[1] - '1'; 
    int currCol = curr[0] - 'a';
    int destRow = dest[1] - '1';
    int destCol = dest[0] - 'a';
    //moving to same place
    if (currRow == destRow && currCol == destCol) 
    {
        return false;
    }
    //moving not in col or row
    if (currRow != destRow && currCol != destCol) 
    {
        return false;
    }
    //row move
    if (currRow == destRow) 
    { 
        int startCol = std::min(currCol, destCol) + 1;
        int endCol = std::max(currCol, destCol);
        int i = 0;
        std::string pos = "";
        for (i = startCol; i < endCol; i++) 
        {
            //create position and check it, the 1 in the beginning is str length
            pos = std::string(1, 'a' + i) + char(currRow + 1);
            if (board.getPiece(pos) != nullptr) 
            {
                return false; 
            }
        }
    }
    //col move
    else if (currCol == destCol) 
    { 
        int startRow = std::min(currRow, destRow) + 1;
        int endRow = std::max(currRow, destRow);
        int i = 0;
        for (i= startRow; i < endRow; i++) 
        {
            //create position and check it, the 1 in the beginning is str length
            std::string pos = std::string(1, 'a' + currCol) + char(i + 1);
            if (board.getPiece(pos) != nullptr) 
            {
                return false;
            }
        }
    }
    //check for same colour 
    Piece* target = board.getPiece(dest);
    if (target != nullptr && target->getColor() == this->getColor()) 
    {
        return false; 
    }
    return true;
}

//!! do half of the king i wiil do a part of it to but make a board to check are code please