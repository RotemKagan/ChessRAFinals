#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "Bishop.h"
#include "Knight.h"
//explain shortly how the board works
//how to we convert from e5 to numbers of the board

Board::Board(): board(WIDTH, std::vector<Piece*>(HEIGHT, 0)) {
	

}

void Board::resetBoard() {
	int i = 0;
	int color1 = 0; //white;
	int color2 = 1; //black

	for (i = 0; i < WIDTH; i++) {
		board[1][i] = new Pawn(color1, "Pawn"); // line of white pawns
		board[HEIGHT - 2][i] = new Pawn(color2, "Pawn"); // line of black pawns
	}

	//white rooks
	board[0][0] = new Rook(color1, "Rook");
	board[0][7] = new Rook(color1, "Rook");

	//black rooks
	board[HEIGHT - 1][0] = new Rook(color2, "Rook");
	board[HEIGHT - 1][7] = new Rook(color2, "Rook");

	//white knights
	board[0][1] = new Knight(color1, "Knight");
	board[0][6] = new Knight(color1, "Knight");

	//black knights
	board[HEIGHT - 1][1] = new Knight(color1, "Knight");
	board[HEIGHT - 1][6] = new Knight(color2, "Knight");

	//white bishops
	board[0][2] = new Bishop(color1, "Bishop");
	board[0][5] = new Bishop(color1, "Bishop");

	//black bishops
	board[HEIGHT- 1][2] = new Bishop(color2, "Bishop");
	board[HEIGHT - 1][5] = new Bishop(color2, "Bishop");

	//white queen
	board[0][3] = new Queen(color1, "Queen");

	//black queen
	board[HEIGHT - 1][3] = new Queen(color2, "Queen");

	//white king
	board[0][4] = new King(color1, "King");

	//black king
	board[HEIGHT - 1][4] = new King(color2, "King");
}

void Board::clearBoard() {
	int i = 0;
	int j = 0;
	Piece* piece = NULL;

	for (i = 0; i < WIDTH; i++) {
		for (j = 0; j < HEIGHT; i++) {
			piece = board[i][j];
			if (piece) {
				delete piece;
			}
		}
	}
}
bool Board::makeMove(std::string move) {
	Piece* cur = NULL;
	Piece* fut = NULL;
	std::string curPos = "";
	std::string futPos = "";
	futPos = move[2] + move[3];
	curPos = move[0] + move[1];
	int col = 0;
	int row = 0;
	
	cur = getPiece(curPos);
	if (!cur) {
		return false;
	}
	
	/*
	if (!cur->isLegal(move, *this)) {
		return false;
	}*/

	setPiece(futPos, cur);
	setPiece(curPos, NULL);

	return true;
}

bool Board::isCheck() {
	int i = 0;
	int j = 0;
	std::string pos = "";
	Piece* piece = NULL;
	for (i = 0; i < WIDTH; i++) {
		for (j = 0; j < HEIGHT; i++) {
			piece = board[i][j];
			pos = char(i + 'a') + char(j + '1');
			if (piece->isUnderCheck(pos, *this)) {
				return true;
			}
		}
	}
}

Piece* Board::getPiece(std::string pos) { //example of pos - "e5"
	int col = 0;
	int row = 0;

	col = pos[1] - '1';
	row = pos[0] - 'a';


	return	board[col][row];
}
//a function we need to return all oponents pieces by requested name
std::string Board::getPostionOfPeace(std::string Name, int color)
{
	std::string allPositions;
	for (char j = 'a'; j <= 'z'; j++)
	{
		for (int i = 1; i <= 8; i++)
		{
			std::string position = std::string(1, j) + std::to_string(i);
			Piece* piece = this->getPiece(position);
			if (piece && piece->getName() == Name && piece->getColor()!=color)
			{
				if (!allPositions.empty()) 
				{
					allPositions += ","; 
				}
				allPositions += position;
			}
		}
	}
	return allPositions;
}
void Board::setPiece(std::string pos, Piece* piece) {
	int col = 0;
	int row = 0;

	col = pos[1] - '1';
	row = pos[0] - 'a';

	board[col][row] = piece;
}


int Board::isLegal(std::string move, Manager* manager) {
	std::string dest = move.substr(2, 2);
	int legalCode = 0;
	Piece* curPiece;
	int color = 0;

	int startCol = move[0] - 'a';
	int startRow = move[1] - '1';
	int endCol = move[2] - 'a';
	int endRow = move[3] - '1';

	std::string reverseMove = ""; //in case we need to return to the starting pos;

	reverseMove = (endCol + 'a') + (endRow + '1') + (startCol + 'a') + (startRow + '1');

	std::string pos = "";
	pos = move[0] + move[1];


	curPiece = getPiece(pos);


	if (!curPiece) {
		return false;
	}

	color = curPiece->getColor();

	legalCode = curPiece->isLegal(move, *this);

	if (legalCode >= 2 || legalCode <= 7) { //if move ilegal
		return legalCode;
	}

	makeMove(move);

	manager->getCurPlayer()->getKing()->isUnderCheck(); //checks if after the current move the king will be in check 



}