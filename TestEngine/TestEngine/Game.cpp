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
	Material * mat = Material::loadMaterial("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");
	triangle = new Triangle(_renderer);
	triangle->setMaterial(mat);
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

void Game::onDraw() {
	triangle->Draw();
}

bool Game::onStop() {
	delete triangle;
	cout << "-OnStop-";
	return true;
}
