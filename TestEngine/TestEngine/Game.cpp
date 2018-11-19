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
	Material * mat = Material::loadMaterial(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
	Material * mat2 = Material::loadMaterial(TEXTURE_VERTEX_SHADER_PATH, TEXTURE_FRAGMENT_SHADER_PATH);
	triangle = new Triangle(_renderer);
	triangle->setMaterial(mat);
	square = new Square(_renderer);
	square->setMaterial(mat);
	square->setScale(5, 5, 5);
	triangle->setScale(6, 6, 6);
	_pepito = 0;
	_vel = 0;
	sprite = new Sprite(_renderer, "image.bmp");
	sprite->setMaterial(mat2);
	sprite->setScale((10.0f), (10.0f), (10.0f));
	sprite->setFrames(102, 101, 512, 512);
	sprite->setFrame(7);
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
	sprite->Draw();
}

bool Game::onStop() {
	delete square;
	delete triangle;
	cout << "-OnStop-";
	return true;
}
