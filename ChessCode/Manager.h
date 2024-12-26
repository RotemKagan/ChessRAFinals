#include "Player.h"


class Manager {
private:
	Board* board;
	Player* playerWhite;
	Player* playerBlack;
	Player* currPlayer;
	Player* otherPlayer;
	//Pipe  pipe

public:
	Manager();
	~Manager();
	void playGame(); //main()
};