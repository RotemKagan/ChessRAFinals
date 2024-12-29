#include "Manager.h"
#include <iostream>
#include <cctype>

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

std::string Manager::getStartMsg(bool isWhiteFirst) { //the first msg that the front end needs
	std::string lastP = "PPPPPPPPRNBQKBNR";
	std::string nonP = "################################";
	std::string firstP = "rnbqkbnrpppppppp";
	std::string ret = "";

	ret = firstP + nonP + lastP;
	return ret;
}


void Manager::playGame() { //main()
	pipe.connect();

	std::string msgToGrp = getStartMsg(true);

	char* strToGrp = msgToGrp.c_str()

	pipe.sendMessageToGraphics(msgToGrp.c_str());



	pipe.close();
}