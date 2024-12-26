#include "Manager.h"
#include <iostream>

Manager::Manager() {
	playerWhite = new Player(0);
	playerBlack = new Player(1);
}
Manager::~Manager() {
	delete playerWhite;
	delete playerBlack;
	board->clearBoard();
}
void Manager::playGame();