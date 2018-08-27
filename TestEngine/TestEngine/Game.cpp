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
	cout << "-OnStart-";
	_pepito = 0;
	return true;
}

bool Game::onUpdate() {
	if(_pepito < 3000) {
		_pepito++;
		cout << endl << "Hay " << _pepito << " pepitos." << endl;
	}
	return true;
}

bool Game::onStop() {
	cout << "-OnStop-";
	return true;
}
