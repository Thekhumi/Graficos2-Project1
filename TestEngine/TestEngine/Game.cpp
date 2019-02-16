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
	//-------------------Collision Manager-------------------------------
	Cmanager = new CollisionManager(2);
	//----------------------Materiales----------------------
	Material * mat = Material::loadMaterial(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
	Material * mat2 = Material::loadMaterial(TEXTURE_VERTEX_SHADER_PATH, TEXTURE_FRAGMENT_SHADER_PATH);
	Material * mat3 = Material::loadMaterial(COLOR_VERTEX_SHADER_PATH, COLOR_FRAGMENT_SHADER_PATH);

	//----------------------Tilemap------------------------------------
	tilemap = new Tilemap("Tilemap/Level1.oel", 16, 480, 640);
	int cont = 0;
	for (size_t i = 0; i < 10; i++){
		for (size_t j = 0; j < 10; j++){
			Tile * temp = new Tile((j*2.0f) - 9.0f, (i*-2.0f) + 9.0f, tilemap, _renderer, "Floor.bmp", true);
			temp->setFrames(16, 16, 624, 336);
			temp->setTilePos(j, i);
			temp->setScale(2, 2, 2);
			temp->setMaterial(mat2);
			tiles.push_back(*temp);	
		}
	}
	//posición de arranque.
	moveCamera(27, 22);
	//----------------figuras-----------------------
	//triangle = new Triangle(_renderer);
	//triangle->setMaterial(mat);
	//square = new Square(_renderer);
	//square->setMaterial(mat);
	//square->setScale(5, 5, 5);
	//triangle->setScale(6, 6, 6);
	//colorCube = new ColorSquare(_renderer);
	//colorCube->setMaterial(mat3);
	//colorCube->setPos((0, 5), 1, -1);
	//colorCube->setScale(5, 5, 1);
	//circle = new Circle(_renderer,120,2);
	//circle->setMaterial(mat);
	//circle->setScale(1, 1, 1);
	//circle->setPosX(-5.5);
	//--------------var de rotacion---------------
	//_vel = 0;

	//----------------------Sprites----------------------
	//sprite = new Sprite(_renderer, "CRASH.bmp",true);
	//wallSprite = new Sprite(_renderer, "image.bmp",false);
	//sprite->setMaterial(mat2);
	//wallSprite->setMaterial(mat2);

	//----------------------Pos Y Scale----------------------------
	//sprite->setScale((5.0f), (5.0f), (5.0f));
	//wallSprite->setScale((5.0f), (5.0f), (5.0f));
	//sprite->setFrames(76, 76, 532, 532);
	//sprite->setPosX(0);
	//sprite->setPosY(0);
	//wallSprite->setPosX(5);
	//----------------------Frames anim----------------------
	//int * frames = new int[7]{ 8,9,10,11,12,13,14};
	//spriteAnimation = new Animation(sprite);
	//spriteAnimation->setAnimation(frames, 7, 5);
	//spriteAnimation->setPlay(true);

	//----------------------Personaje----------------------
	//Personaje = new Avatar(sprite, spriteAnimation);
	//Personaje->getSprite()->setCollider(Personaje->getSprite()->getPos(), 2.0f, 2.0f, false);

	//----------------------Pared----------------------
	//wallSprite->setCollider(wallSprite->getPos(), 5.0f, 5.0f, false);
	//wallSprite->getBoxCollider()->setMass(5.0f);

	//----------------------Añadir a CM----------------------
	//Cmanager->AddEntity(Personaje->getSprite(), 0);
	//Cmanager->AddEntity(wallSprite, 1);

	//tiles extremos
	//tiles[0].setFrame(199);
	//tiles[9].setFrame(199);
	//tiles[90].setFrame(199);
	//tiles[99].setFrame(199);
	return true;
}

bool Game::onUpdate(double deltaTime) {
	_timer += 1 * deltaTime;
	if (input(265) && _timer > 0.15) {
		moveCamera(0, -1);
		_timer = 0;
	}
	if (input(264) && _timer > 0.15) {
		moveCamera(0, 1);
		_timer = 0;
	}
	if (input(263) && _timer > 0.15) {
		moveCamera(-1, 0);
		_timer = 0;
	}
	if (input(262) && _timer > 0.15) {
		moveCamera(1, 0);
		_timer = 0;
	}
	//_vel +=  1 * deltaTime;
	//triangle->setRotZ(_vel);
	//square->setRotZ(_vel);
	//Personaje->update(deltaTime);
	Cmanager->CheckLayers();
	//input
	return true;
}

void Game::onDraw() {
	for (int i = 0; i < tiles.size(); i++){
		tiles.at(i).Draw();
	}
	//square->Draw();
	//triangle->Draw();
	//colorCube->Draw();
	//circle->Draw();
	//wallSprite->Draw();
	//sprite->Draw();
}

void Game::moveCamera(int x, int y) {
	for (int i = 0; i < tiles.size(); i++) {
		tiles.at(i).moveTilePos(x, y);
	}
}

bool Game::onStop() {
	//delete square;
	//delete triangle;
	//delete circle;
	//delete wallSprite;
	//delete sprite;
	//delete colorCube;

	cout << "-OnStop-";
	return true;
}
