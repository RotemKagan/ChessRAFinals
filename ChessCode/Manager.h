#include "Player.h"
#include "Pipe.h"

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
	std::string getStartMsg(bool isWhiteFirst);
	void playGame(); //main()
};