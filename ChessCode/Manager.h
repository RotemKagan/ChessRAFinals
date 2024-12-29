#include "Player.h"
#include "Pipe.h"
#include "Board.h"

class Manager {
private:
	Board* board;
	Player* playerWhite;
	Player* playerBlack;
	Player* currPlayer;
	Player* otherPlayer;
	Pipe  pipe;

public:
	Manager(Pipe& p);
	~Manager();
	char* getStartMsg(bool isWhiteFirst);
	void playGame(); //main()
};