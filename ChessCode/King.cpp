#include "King.h"
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
bool King::isUnderCheck(std::string cPos, Board board) {
    int i = 0;
    Piece* piece = NULL;
    //converts
    int currRow = cPos[1] - '1';
    int currCol = cPos[0] - 'a';

    int newRow = 0;
    int newCol = 0;

    std::string pos = "";

    //checks for straight line Checks
    // in each check it will check from the king pos up/down, if it found same color piece, it will go for the next check, if before that it find other color rook/queen, it will be check
    // add when there are other color piece and its not queen/rook, move to next check
    //colUp - same col
    
    newRow = currRow;
    newCol = currCol;
    for (i = currRow; i < WIDTH; i++) {
        pos = char(newCol) + char(i + 1);
        piece = board.getPiece(pos);
        if (piece->getColor() != this->getColor()) {
            if (piece->getName() == "Rook" || piece->getName() == "Queen") {
                return true;
            }
        }
        else {
            i = WIDTH;
        }
    }

    //colDown - same col

    newRow = currRow;
    newCol = currCol;
    for (i = currRow; i > 1; i--) {
        pos = char(newCol) + char(i - 1);
        piece = board.getPiece(pos);
        if (piece->getColor() != this->getColor()) {
            if (piece->getName() == "Rook" || piece->getName() == "Queen") {
                return true;
            }
        }
        else {
            i = 1;
        }
    }

    //rowUp - same row

    newRow = currRow;
    newCol = currCol;
    for (i = currCol; i < HEIGHT; i++) {
        pos = char(i + 1) + char(currRow);
        piece = board.getPiece(pos);
        if (piece->getColor() != this->getColor()) {
            if (piece->getName() == "Rook" || piece->getName() == "Queen") {
                return true;
            }
        }
        else {
            i = HEIGHT;
        }
    }

    //rowDown - same row

    newRow = currRow;
    newCol = currCol;
    for (i = currCol; i > 1; i--) {
        pos = char(i - 1) + char(currRow);
        piece = board.getPiece(pos);
        if (piece->getColor() != this->getColor()) {
            if (piece->getName() == "Rook" || piece->getName() == "Queen") {
                return true;
            }
        }
        else {
            i = 1;
        }
    }
}

