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
int Rook::isLegal(std::string move, Board board)
{
    std::string dest = std::string(1, move[2]) + std::string(1, move[3]);
    std::string src = std::string(1, move[0]) + std::string(1, move[1]);
    int startCol = move[0] - 'a';
    int startRow = move[1] - '1';
    int endCol = move[2] - 'a';
    int endRow = move[3] - '1';
    if (board.getPiece(src)->getName() != "Queen")
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
    //moving to same place
    if (startRow == endRow && startCol == endCol) 
    {
        return 7;
    }
    //moving not in col or row
    if (startRow != endRow && startCol != endCol) 
    {
        return 6;
    }
    //row move
    if (startRow == endRow) 
    { 
        startCol = min(startCol, endCol) + 1;
        endCol = max(startCol, endCol);
        int i = 0;
        std::string pos = "";
        for (i = startCol; i < endCol; i++) 
        {
            //create position and check it, the 1 in the beginning is str length
            pos = std::string(1, 'a' + i) + char(startRow + 1);
            if (board.getPiece(pos) != nullptr) 
            {
                return 6; 
            }
        }
    }
    //col move
    else if (startCol == endCol) 
    { 
        startRow = min(startRow, endRow) + 1;
        endRow = max(startRow, endRow);
        int i = 0;
        for (i= startRow; i < endRow; i++) 
        {
            //create position and check it, the 1 in the beginning is str length
            std::string pos = std::string(1, 'a' + startCol) + char(i + 1);
            if (board.getPiece(pos) != nullptr) 
            {
                return 6;
            }
        }
    }
    //check for same colour 
    Piece* target = board.getPiece(dest);
    if (target != nullptr && target->getColor() == this->getColor()) 
    {
        return 3; 
    }
    return 0;
}

bool Rook::isUnderCheck(std::string pos, Board board) {
    return false;
}

//!! do half of the king i wiil do a part of it to but make a board to check are code please