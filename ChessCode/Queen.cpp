#include "Queen.h"
Queen::Queen(int color, std::string name)
	:Piece(color, name)
{
}
Queen::~Queen()
{
}
void Queen::makeMove(std::string move, Board board)
{
	board.makeMove(move);
}
int Queen::isLegal(std::string move, Board board)
{
    std::string dest = move.substr(2, 2);
	int startCol = move[0] - 'a';
	int startRow = move[1] - '1';
	int endCol = move[2] - 'a';
	int endRow = move[3] - '1';
	//if same place
	if (startCol == endCol && startRow == endRow)
	{
		return false;
	}
	//if not digonal or in col or row
	if ((abs(endCol - startCol) != abs(endRow - startRow)) && (startRow != endRow && startCol != endCol))
	{
		return false;
	}
    //if the move was digonal check like in the bishop
    if (abs(endCol - startCol) == abs(endRow - startRow))
    {

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
    }
    //if the mov is like a rook (in col or in row)
    else if (startRow == endRow || startCol == endCol) 
    {
        if (startRow == endRow)
        {
            int start = std::min(startCol, endCol) + 1;
            int end = std::max(startCol, endCol);
            int i = 0;
            std::string pos = "";
            for (i = start; i < end; i++)
            {
                //create position and check it, the 1 in the beginning is str length
                pos = std::string(1, 'a' + i) + char(startRow + 1);
                if (board.getPiece(pos) != nullptr)
                {
                    return false;
                }
            }
        }
        //col move
        else if (startCol == endCol)
        {
            int start = std::min(startRow, endRow) + 1;
            int end = std::max(startRow, endRow);
            int i = 0;
            for (i = start; i < end; i++)
            {
                //create position and check it, the 1 in the beginning is str length
                std::string pos = std::string(1, 'a' + startCol) + char(i + 1);
                if (board.getPiece(pos) != nullptr)
                {
                    return false;
                }
            }
        }
    }
    //check if it didnt capture its own piece
    Piece* targetPiece = board.getPiece(dest);
    if (targetPiece != nullptr && targetPiece->getColor() == this->getColor())
    {
        return false;
    }
    return true;
}
bool Queen::isUnderCheck(std::string pos, Board board) 
{
	return false;
}