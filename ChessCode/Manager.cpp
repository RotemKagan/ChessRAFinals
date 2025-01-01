#include "Manager.h"
#include <iostream>
#include <cctype>
#include <cstring>



Manager::Manager(Pipe& p) {
	playerWhite = new Player(0);
	currPlayer = NULL;
	otherPlayer = NULL;
	playerBlack = new Player(1);
	pipe = p;
	board = new Board();

}
Manager::~Manager() {
	delete playerWhite;
	delete playerBlack;
	board->clearBoard();
	delete board;
}

Player* Manager::getCurPlayer()const {
	return currPlayer;
}

Player* Manager::getOtherPlayer()const {
	return otherPlayer;
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

	this->board->resetBoard(); //create the pieces in there starting pos on the board

	char* firstMsgToGrp = getStartMsg(true);
	std::string userMove = "";
	std::string pos = "";

	Player* tempPlayer = NULL;

	int isLegal = false;

	char msgToGrp[2] = "";

	char* msgToGrpPointer = NULL;

	pos = WHITE_K_COL + WHITE_K_ROW;
	playerWhite->setKing(board->getPiece(pos));

	pos = BLACK_K_COL + BLACK_K_ROW;
	playerBlack->setKing(board->getPiece(pos));

	pipe.sendMessageToGraphics(firstMsgToGrp); // sends first msg to forntend, so the graphics will be initialized

	currPlayer = playerWhite;
	otherPlayer = playerBlack;

	while (playerWhite->getKing() && playerBlack->getKing()){
		userMove = pipe.getMessageFromGraphics();
		isLegal = board->isLegal(userMove, this);

		if (isLegal < 2 || isLegal > 7) { //if the move is legal
			board->makeMove(userMove);

			//switching the curent players
			tempPlayer = currPlayer;
			currPlayer = otherPlayer;
			otherPlayer = tempPlayer;
		}

		msgToGrp[0] = isLegal + '0';
		msgToGrp[1] = NULL;

		msgToGrpPointer = msgToGrp;

		pipe.sendMessageToGraphics(msgToGrpPointer);

	}

	delete board;
	pipe.close();
}