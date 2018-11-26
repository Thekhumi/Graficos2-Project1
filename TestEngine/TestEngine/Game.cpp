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
	Cmanager = new CollisionManager(2);
	Material * mat = Material::loadMaterial(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
	Material * mat2 = Material::loadMaterial(TEXTURE_VERTEX_SHADER_PATH, TEXTURE_FRAGMENT_SHADER_PATH);
	triangle = new Triangle(_renderer);
	triangle->setMaterial(mat);
	square = new Square(_renderer);
	square->setMaterial(mat);
	square->setScale(5, 5, 5);
	triangle->setScale(6, 6, 6);
	_vel = 0;
	sprite = new Sprite(_renderer, "CRASH2.bmp");
	wallSprite = new Sprite(_renderer, "image.bmp");
	sprite->setMaterial(mat2);
	wallSprite->setMaterial(mat2);
	sprite->setScale((5.0f), (5.0f), (5.0f));
	wallSprite->setScale((5.0f), (5.0f), (5.0f));
	sprite->setFrames(76, 76, 532, 532);
	sprite->setPosX(0);
	sprite->setPosY(0);
	wallSprite->setPosX(5);
	int * frames = new int[7]{ 8,9,10,11,12,13,14};
	spriteAnimation = new Animation(sprite);
	spriteAnimation->setAnimation(frames, 7, 5);
	spriteAnimation->setPlay(true);
	Personaje = new Avatar(sprite, spriteAnimation);
	Personaje->getSprite()->setCollider(Personaje->getSprite()->getPos(), 2.0f, 2.0f, false);
	wallSprite->setCollider(wallSprite->getPos(), 5.0f, 5.0f, false);
	Cmanager->AddEntity(Personaje->getSprite(), 0);
	Cmanager->AddEntity(wallSprite, 1);
	return true;
}

bool Game::onUpdate(double deltaTime) {
	_vel +=  1 * deltaTime;
	triangle->setRotZ(_vel);
	square->setRotZ(_vel);
	Personaje->update(deltaTime);
	Cmanager->CheckLayers();
	return true;
}

void Game::onDraw() {
	square->Draw();
	triangle->Draw();
	sprite->Draw();
	wallSprite->Draw();
}

bool Game::onStop() {
	delete square;
	delete triangle;
	cout << "-OnStop-";
	return true;
}
