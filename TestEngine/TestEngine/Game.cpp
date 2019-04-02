#include "Game.h"
#include <iostream>
using namespace std;


Game::Game(){
}


Game::~Game()
{
}

bool Game::onStart() {
	cout << "-OnStart-";
	return true;
}

bool Game::onUpdate(double deltaTime) {
	return true;
}

void Game::onDraw() {
	
}

bool Game::onStop() {
	cout << "-OnStop-";
	return true;
}
