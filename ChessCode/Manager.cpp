#include "Manager.h"
#include <iostream>

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
void Manager::playGame();