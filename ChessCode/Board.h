#ifndef BOARD_H
#define BOARD_H

#define WIDTH 8
#define HEIGHT 8





#include <iostream>
#include <vector>
#include "Piece.h"
#include "Manager.h"

// White start at the first and second rows, and Black at the seventh and eighth

class Piece;

class Board {
private:
	std::vector<std::vector<Piece*>> board;
public:
	Board();

	void clearBoard();
	
	void resetBoard(); //this func will create each piece and place it to the board it its starting pos

	bool makeMove(std::string move);
	bool isCheck();

	int isLegal(std::string move, Manager* manager);
	std::string getPostionOfPeace(std::string Name, int color);

	Piece* getPiece(std::string pos);
	void setPiece(std::string pos, Piece* piece);
};


#endif