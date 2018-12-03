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
	//Collision Manager
	Cmanager = new CollisionManager(2);

	Material * mat = Material::loadMaterial(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
	Material * mat2 = Material::loadMaterial(TEXTURE_VERTEX_SHADER_PATH, TEXTURE_FRAGMENT_SHADER_PATH);
	Material * mat3 = Material::loadMaterial(COLOR_VERTEX_SHADER_PATH, COLOR_FRAGMENT_SHADER_PATH);
	//figuras
	triangle = new Triangle(_renderer);
	triangle->setMaterial(mat);
	square = new Square(_renderer);
	square->setMaterial(mat);
	square->setScale(5, 5, 5);
	triangle->setScale(6, 6, 6);
	colorCube = new ColorSquare(_renderer);
	colorCube->setMaterial(mat3);
	colorCube->setPos((0, 5), 1, -1);
	colorCube->setScale(5, 5, 1);
	circle = new Circle(_renderer,120,2);
	circle->setMaterial(mat);
	circle->setScale(1, 1, 1);
	circle->setPosX(-5.5);
	//var de rotacion
	_vel = 0;

	//Sprites
	sprite = new Sprite(_renderer, "CRASH.bmp",true);
	wallSprite = new Sprite(_renderer, "image.bmp",false);
	sprite->setMaterial(mat2);
	wallSprite->setMaterial(mat2);

	//Pos Y Scale
	sprite->setScale((5.0f), (5.0f), (5.0f));
	wallSprite->setScale((5.0f), (5.0f), (5.0f));
	sprite->setFrames(76, 76, 532, 532);
	sprite->setPosX(0);
	sprite->setPosY(0);
	wallSprite->setPosX(5);
	//Frames anim
	int * frames = new int[7]{ 8,9,10,11,12,13,14};
	spriteAnimation = new Animation(sprite);
	spriteAnimation->setAnimation(frames, 7, 5);
	spriteAnimation->setPlay(true);

	//Personaje
	Personaje = new Avatar(sprite, spriteAnimation);
	Personaje->getSprite()->setCollider(Personaje->getSprite()->getPos(), 2.0f, 2.0f, false);

	//Pared
	wallSprite->setCollider(wallSprite->getPos(), 5.0f, 5.0f, false);
	wallSprite->getBoxCollider()->setMass(5.0f);

	//Add Entities to Collision Manager
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
	colorCube->Draw();
	circle->Draw();
	wallSprite->Draw();
	sprite->Draw();
}

bool Game::onStop() {
	delete square;
	delete triangle;
	cout << "-OnStop-";
	return true;
}
