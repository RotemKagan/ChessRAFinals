#include "Bishop.h"
Bishop::Bishop(int color, std::string name) 
	:Piece(color,name)
{
}
Bishop::~Bishop() 
{

}
void Bishop::makeMove(std::string move, Board board)
{
	board.makeMove(move);
}
bool Bishop::isLegal(std::string toMove, Board board)
{
    int startCol = toMove[0] - 'a';  
    int startRow = toMove[1] - '1';
    int endCol = toMove[3] - 'a';  
    int endRow = toMove[4] - '1'; 

    // if not diagonal
    if (abs(endCol - startCol) != abs(endRow - startRow)) 
    {
        return false;
    }
    //if same place
    if (startCol == endCol && startRow) 
    {
        return false;
    }
    int isUpCol;
    int isUpRow;
    //moving right or left
    if (endCol > startCol) 
    {
        isUpCol = 1;
    }
    else 
    {
        isUpCol = -1;
    }
    //moving up or down
    if (endRow > startRow) 
    {
        isUpRow = 1;
    }
    else 
    {
        isUpRow = -1;
    }
    //start from the first next square in the bishops path
    int col = startCol + isUpCol;
    int row = startRow + isUpRow;
    //till it reaches the final square of the path
    while (col != endCol && row != endRow) 
    {
        //create a position to check if there is a piece in the path, 1 is the size of the string
        std::string pos = std::string(1, 'a' + col) + char(row + 1);
        if (board.getPiece(pos) != nullptr)
        {  
            return false;
        }
        //move to the next square in the path
        col += isUpCol;
        row += isUpRow;
    }
    //check if it didnt capture its own piece
    Piece* targetPiece = board.getPiece(toMove);
    if (targetPiece != nullptr && targetPiece->getColor() == this->getColor()) 
    {
        return false; 
    }

    return true;
}

bool Bishop::isUnderCheck(std::string pos, Board board) 
{
	return false;
}
