#include "Board.h"

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
void resetBoard();
void makeMove(std::string move) {
	Piece* cur = NULL;
	Piece* fut = NULL;
	std::string curPos = "";
	std::string futPos = "";
	futPos = move[2] + move[3];
	curPos = move[0] + move[1];
	
}
bool isCheck();

Piece* Board::getPiece(std::string pos) { //example of pos - "e5"
	int col = 0;
	int row = 0;

	col = pos[0] - '1';
	row = pos[1] - 'a';


	return	board[col][row];
}