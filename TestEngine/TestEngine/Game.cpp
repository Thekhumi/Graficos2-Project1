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
	_scale = 5;
	cout << "-OnStart-";
	Material * mat = Material::loadMaterial("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");
	triangle = new Triangle(_renderer);
	triangle->setMaterial(mat);
	square = new Square(_renderer);
	square->setMaterial(mat);
	square->setScale(5, 5, 5);
	triangle->setScale(6, 6, 6);
	_pepito = 0;
	_vel = 0;
	unsigned int test = TextureImporter::loadBMP("image.bmp");
	if (test) {
		cout << "Funciona!";
	}
	return true;
}

bool Game::onUpdate(double deltaTime) {
	if(_pepito < 3000) {
		_pepito++;
		cout << endl << "Hay " << _pepito << " pepitos." << endl;
		_vel +=  1 * deltaTime;
		triangle->setRotZ(_vel);
		square->setRotZ(_vel);
	}
	return true;
}

void Game::onDraw() {
	square->Draw();
	triangle->Draw();
}

bool Game::onStop() {
	delete square;
	delete triangle;
	cout << "-OnStop-";
	return true;
}
