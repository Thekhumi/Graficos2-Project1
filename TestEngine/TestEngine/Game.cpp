#include "Game.h"
#include <iostream>
using namespace std;


Game::Game()
{
}


Game::~Game()
{
}

bool Game::onStart() {
	cout << "OnStart->";
	_pepito = 0;
	return true;
}

bool Game::onUpdate() {
	_pepito++;
	cout << "Hay " << _pepito << " pepitos."<< endl;
	if (_pepito >= 100) {
		return false;
	}
	return true;
}

bool Game::onStop() {
	cout << "OnStop->";
	return true;
}
