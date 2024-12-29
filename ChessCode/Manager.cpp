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

	char* msgToGrp = getStartMsg(true);

	pipe.sendMessageToGraphics(msgToGrp);



	pipe.close();
}