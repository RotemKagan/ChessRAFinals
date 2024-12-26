#include "Player.h"
#include <iostream>

Player::Player(int _color) {
	color = _color;
}

Player::~Player() {
	color = 0;
}

int Player::getColor()const {
	return color;
}