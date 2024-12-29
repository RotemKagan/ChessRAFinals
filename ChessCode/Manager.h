#include "Player.h"
#include "Pipe.h"
#include "Board.h"

#define BLACK_K_COL 'e'
#define BLACK_K_ROW '8'
#define WHITE_K_COL 'e'
#define WHITE_K_ROW '1'
//kings pos in there starting pos

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

	Player* getCurPlayer()const;
	Player* getOtherPlayer()const;

};