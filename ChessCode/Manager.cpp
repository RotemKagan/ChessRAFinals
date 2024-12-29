#include "Manager.h"
#include <iostream>
#include <cctype>
#include <cstring>



Manager::Manager(Pipe& p) {
	playerWhite = new Player(0);
	playerBlack = new Player(1);
	pipe = p;
}
Manager::~Manager() {
	delete playerWhite;
	delete playerBlack;
	board->clearBoard();
}

char* Manager::getStartMsg(bool isWhiteFirst) { //the first msg that the front end needs
	std::string lastP = "PPPPPPPPRNBQKBNR";
	std::string nonP = "################################";
	std::string firstP = "rnbqkbnrpppppppp";
	std::string full = "";
	char msg[] = "#PPPPPPPPRNBQKBNR###############################rnbqkbnrpppppppp";
	char* ret = msg;
	return ret;
}


void Manager::playGame() { //main()
	pipe.connect();

	Board* board;

	board->resetBoard(); //create the pieces in there starting pos on the board

	char* msgToGrp = getStartMsg(true);
	std::string userMove = "";
	std::string pos = "";

	Player* tempPlayer = NULL;

	bool isLegal = false;

	std::string msgToGraphics = "";

	pos = WHITE_K_COL + WHITE_K_ROW;
	playerWhite->setKing(board->getPiece(pos));

	pos = BLACK_K_COL + BLACK_K_ROW;
	playerBlack->setKing(board->getPiece(pos));

	pipe.sendMessageToGraphics(msgToGrp); // sends first msg to forntend, so the graphics will be initialized

	currPlayer = playerWhite;
	otherPlayer = playerBlack;

	while (playerWhite->getKing() && playerBlack->getKing()){
		userMove = pipe.getMessageFromGraphics();
		isLegal = board->isLegal(userMove);

		if (isLegal) {
			board->makeMove(userMove);

			tempPlayer = currPlayer;
			currPlayer = otherPlayer;
			otherPlayer = tempPlayer;



		}

	}

	pipe.close();
}