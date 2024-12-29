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
int Bishop::isLegal(std::string move, Board board)
{
    std::string dest = std::string(1, move[2]) + std::string(1, move[3]);
    std::string src = std::string(1, move[0]) + std::string(1, move[1]);
    int startCol = move[0] - 'a';  
    int startRow = move[1] - '1';
    int endCol = move[2] - 'a';  
    int endRow = move[3] - '1'; 
    if (board.getPiece(src)->getName()!="Bishop")
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
    // if not diagonal
    if (abs(endCol - startCol) != abs(endRow - startRow)) 
    {
        return 6;
    }
    //if same place
    if (startCol == endCol && startRow==endRow) 
    {
        return 7;
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
            return 6;
        }
        //move to the next square in the path
        col += isUpCol;
        row += isUpRow;
    }
    //check if it didnt capture its own piece
    Piece* targetPiece = board.getPiece(dest);
    if (targetPiece != nullptr && targetPiece->getColor() == this->getColor()) 
    {
        return 3; 
    }
    //didnt check if it causes check
    return 0;
}

bool Bishop::isUnderCheck(std::string pos, Board board) 
{
	return false;
}
