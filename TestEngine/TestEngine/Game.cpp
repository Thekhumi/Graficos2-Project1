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
	int * frames = new int[20]{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	spriteAnimation = new Animation(sprite);
	spriteAnimation->setAnimation(frames, 20, 30);
	spriteAnimation->setPlay(true);
	return true;
}

bool Game::onUpdate(double deltaTime) {
	_vel +=  1 * deltaTime;
	triangle->setRotZ(_vel);
	square->setRotZ(_vel);
	spriteAnimation->update(deltaTime);
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
