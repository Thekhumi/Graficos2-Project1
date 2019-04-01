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
	
}

void Game::onDraw() {
	
}

bool Game::onStop() {
	cout << "-OnStop-";
	return true;
}
