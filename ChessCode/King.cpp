#include "King.h"
#include "Piece.h"
#include "Pawn.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include <iostream>
#include <cmath>

King::King(int color, std::string name): Piece(color, name) {
}
King::~King() {

}
void King::makeMove(std::string move, Board board) {
	board.makeMove(move);
}
int King::isLegal(std::string move, Board board) {
    std::string dest = std::string(1, move[2]) + std::string(1, move[3]);
    std::string curr = std::string(1, move[0]) + std::string(1, move[1]);
    int startCol = move[0] - 'a';
    int startRow = move[1] - '1';
    int endCol = move[2] - 'a';
    int endRow = move[3] - '1';
    if (board.getPiece(curr)->getName() != "King")
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

    Piece* piece = NULL;
    //checks for same move
    if (startRow == endRow && startCol == endCol)
    {
        return 7;
    }

    //checks if the move is in 1 move range, if not returns false
    if (std::abs(startRow - endRow) > 1 || std::abs(startCol - endCol)) 
    {
        return 6;
    }

    // checks if there is a piece same color in dest pos, if yes returns false
    piece = board.getPiece(dest);
    if (piece) {
        if (piece->getColor() == this->getColor()) 
        {
            return 3;
        }
    }

    // checks if there check in dest pos
    if (isUnderCheck(dest, board)) {
        return 4;
    }

    return 0;
}
bool King::isUnderCheck(std::string cPos, Board board) 
{
    int i = 0;
    Piece* piece = NULL;
    //converts
    int currRow = cPos[1] - '1';
    int currCol = cPos[0] - 'a';
    std::string QueenPos = "";
    std::string KnightPos = "";
    std::string PawnPos = "";
    std::string BishopPos = "";
    std::string RookPos = "";
    std::string Move = "";
    //use the help fucntion to get all the postions of oposite side pieces
    QueenPos = board.getPostionOfPeace("Queen", this->color);
    KnightPos = board.getPostionOfPeace("Knight", this->color);
    BishopPos = board.getPostionOfPeace("Bishop", this->color);
    PawnPos = board.getPostionOfPeace("Pawn", this->color);
    int start = 0;
    int end = 0;
    //in each part from here i itereate thorugh all the positions and check if the piece from the start position can eat the king-checks the king now
    //Rotem please comment the code some more
    //for the pawn
    while ((end = PawnPos.find(',', start)) != std::string::npos) 
    {

        std::string pos = PawnPos.substr(start, end - start);

        Piece* piece = board.getPiece(pos);
        Pawn* pawn = new Pawn(piece->getColor(), piece->getName());
        Move = pos + cPos;
        if (pawn && pawn->isLegal(Move,board))
        {
            delete (pawn);
            return true;
        }
        delete (pawn);
        start = end + 1;
    }
    std::string lastPos = PawnPos.substr(start);
    if (!lastPos.empty()) 
    {
        Piece* piece= board.getPiece(lastPos);
        Pawn* pawn = new Pawn(piece->getColor(), piece->getName());
        Move = lastPos + cPos;
        if (pawn && pawn->isLegal(Move, board)) 
        {
            delete (pawn);
            return true;
        }
        delete (pawn);
    }

    //now for the bishop
    start = 0;
    end = 0;

    while ((end = BishopPos.find(',', start)) != std::string::npos)
    {

        std::string pos = BishopPos.substr(start, end - start);

        Piece* piece = board.getPiece(pos);
        Bishop* bishop = new Bishop(piece->getColor(), piece->getName());
        Move = pos + cPos;
        if (bishop && bishop->isLegal(Move, board))
        {
            delete(bishop);
            return true;
        }
        delete(bishop);
        start = end + 1;
    }
    std::string lastPos = BishopPos.substr(start);
    if (!lastPos.empty())
    {
        Piece* piece = board.getPiece(lastPos);
        Bishop* bishop = new Bishop(piece->getColor(), piece->getName());
        Move = lastPos + cPos;
        if (bishop && bishop->isLegal(Move, board))
        {
            delete(bishop);
            return true;
        }
        delete(bishop);
    }


    //now for the queen
    start = 0;
    end = 0;

    while ((end = QueenPos.find(',', start)) != std::string::npos)
    {

        std::string pos = QueenPos.substr(start, end - start);

        Piece* piece = board.getPiece(pos);
        Queen* queen = new Queen(piece->getColor(), piece->getName());
        Move = pos + cPos;
        if (queen && queen->isLegal(Move, board))
        {
            delete(queen);
            return true;
        }
        delete(queen);
        start = end + 1;
    }
    std::string lastPos = QueenPos.substr(start);
    if (!lastPos.empty())
    {
        Piece* piece = board.getPiece(lastPos);
        Queen* queen = new Queen(piece->getColor(), piece->getName());
        Move = lastPos + cPos;
        if (queen && queen->isLegal(Move, board))
        {
            delete(queen);
            return true;
        }
        delete(queen);
    }


    //now for the rook
    start = 0;
    end = 0;

    while ((end = RookPos.find(',', start)) != std::string::npos)
    {

        std::string pos = RookPos.substr(start, end - start);

        Piece* piece = board.getPiece(pos);
        Rook* rook = new Rook(piece->getColor(), piece->getName());
        Move = pos + cPos;
        if (rook && rook->isLegal(Move, board))
        {
            delete(rook);
            return true;
        }
        delete(rook);
        start = end + 1;
    }
    std::string lastPos = RookPos.substr(start);
    if (!lastPos.empty())
    {
        Piece* piece = board.getPiece(lastPos);
        Rook* rook = new Rook(piece->getColor(), piece->getName());
        Move = lastPos + cPos;
        if (rook && rook->isLegal(Move, board))
        {
            delete(rook);
            return true;
        }
        delete(rook);
    }

    //now for the knight wich is the last piece that can check cause king cant
    start = 0;
    end = 0;

    while ((end = KnightPos.find(',', start)) != std::string::npos)
    {

        std::string pos = KnightPos.substr(start, end - start);

        Piece* piece = board.getPiece(pos);
        Knight* kngiht = new Knight(piece->getColor(), piece->getName());
        Move = pos + cPos;
        if (kngiht && kngiht->isLegal(Move, board))
        {
            delete(kngiht);
            return true;
        }
        delete(kngiht);
        start = end + 1;
    }
    std::string lastPos = KnightPos.substr(start);
    if (!lastPos.empty())
    {
        Piece* piece = board.getPiece(lastPos);
        Knight* kngiht = new Knight(piece->getColor(), piece->getName());
        Move = lastPos + cPos;
        if (kngiht && kngiht->isLegal(Move, board))
        {
            delete(kngiht);
            return true;
        }
        delete(kngiht);
    }
}

