#include "Board.h"
#include "Piece.h"

class Pawn : public Piece {
private:
	int hasMoved; //to know if it can be moved 2 rows.

public:
	Pawn(int color, std::string name);
	~Pawn();

	virtual void makeMove(std::string move, Board board) override;
	virtual bool isLegal(std::string move, Board board) override;
	virtual bool isUnderCheck(std::string pos, Board board) override;
};