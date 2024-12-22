#include "Board.h"
//explain shortly how the board works
//how to we convert from e5 to numbers of the board

Board::Board(): board(WIDTH, std::vector<Piece*>(HEIGHT, 0)) {
}

void Board::clearBoard() {
	int i = 0;
	int j = 0;
	for (i = 0; i < WIDTH; i++) {
		for (j = 0; j < HEIGHT; i++) {
			board[i][j] = 0;
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
	
	if (!cur->isLegal(move, *this)) {
		return false;
	}

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

void Board::setPiece(std::string pos, Piece* piece) {
	int col = 0;
	int row = 0;

	col = pos[1] - '1';
	row = pos[0] - 'a';

	board[col][row] = piece;
}