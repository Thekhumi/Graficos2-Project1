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
	Material * mat = Material::loadMaterial(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
	square = new Square(_renderer);
	square->setMaterial(mat);
	square->setScale(1,1,1);
	_renderer->setProjectiveMatrixPerspective(45.0f, 640.0f/640.0f, 0.1f, 100.0f);
	_renderer->setProjectionMatrixOrtho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f);
	_renderer->setProjectionMode(Rendering::MODE::ORTHO);
	return true;
}

bool Game::onUpdate(double deltaTime) {
	square->setPosX(square->getPosX() - 0.02f);
	return true;
}

void Game::onDraw() {
	square->Draw();
}

bool Game::onStop() {
	cout << "-OnStop-";
	return true;
}
