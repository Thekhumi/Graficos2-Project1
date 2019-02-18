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
	sprite = new Sprite(_renderer, "Warrior.bmp",true);
	//Config Monsters
	for (int i = 0; i < enemyCount; i++){
		Sprite * temp = new Sprite(_renderer,"Player0.bmp", true);
		temp->setFrames(16,16,240,128);
		temp->setFrame(97);
		temp->setScale(2, 2, 2);
		temp->setPosZ(0.6);
		temp->setMaterial(mat2);
		enemies.push_back(*new Monster(temp));
	}
	enemies[0].setTilePos(33,17);
	enemies[0].setMove(true);
	enemies[1].setTilePos(17, 16);
	enemies[1].setMove(true);
	enemies[2].setTilePos(9, 23);
	enemies[2].setMove(true);
	enemies[3].setTilePos(11, 17);
	enemies[3].setMove(true);
	enemies[4].setTilePos(0, 26);
	//wallSprite = new Sprite(_renderer, "image.bmp",false);
	sprite->setMaterial(mat2);
	//wallSprite->setMaterial(mat2);
	//PowerUp
	Sprite * powerUpSpr = new Sprite(_renderer, "MedWep.bmp",true);
	powerUpSpr->setMaterial(mat2);
	powerUpSpr->setFrames(16, 16, 32, 128);
	powerUpSpr->setScale(2, 2, 1);
	powerUpSpr->setPosZ(0.4);
	powerUpSpr->setFrame(0);
	powerUp = new SwordPowerup(powerUpSpr,1,12);
	victoryScreen = new Sprite(_renderer, "Victory.bmp", true);
	victoryScreen->setMaterial(mat2);
	victoryScreen->setScale(20, 8, 1);
	//----------------------Pos Y Scale----------------------------
	sprite->setScale((2.0f), (2.0f), (2.0f));
	//wallSprite->setScale((5.0f), (5.0f), (5.0f));
	sprite->setFrames(16, 16, 64, 64);
	sprite->setFrame(0);
	sprite->setPosX(tiles[45].getPosX());
	sprite->setPosY(tiles[45].getPosY());
	sprite->setPosZ(0.5);
	guerrero = new Guerrero(sprite);
	guerrero->setTilePos(tiles[45].getTilePosX(), tiles[45].getTilePosY());
	guerrero->generateTeleportTile(36, 24, 36, 20);
	guerrero->generateTeleportTile(37, 24, 37, 20);
	
	guerrero->generateTeleportTile(23, 16, 19, 16);
	guerrero->generateTeleportTile(23, 17, 19, 17);
	guerrero->generateTeleportTile(23, 18, 19, 18);
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
	x = 0;
	y = 0;
	_timer += 1 * deltaTime;
	if (guerrero->getAlive()) {
		if (input(265) && _timer > 0.15 &&
			guerrero->move(3, tilemap->getTile(guerrero->getTilePosX(), guerrero->getTilePosY() - 1))) {
			moveCamera(0, -1);
			_timer = 0;
		}
		if (input(264) && _timer > 0.15 &&
			guerrero->move(0, tilemap->getTile(guerrero->getTilePosX(), guerrero->getTilePosY() + 1))) {
			moveCamera(0, 1);
			_timer = 0;
		}
		if (input(263) && _timer > 0.15 &&
			guerrero->move(1, tilemap->getTile(guerrero->getTilePosX() - 1, guerrero->getTilePosY()))) {
			moveCamera(-1, 0);
			_timer = 0;
		}
		if (input(262) && _timer > 0.15 &&
			guerrero->move(2, tilemap->getTile(guerrero->getTilePosX() + 1, guerrero->getTilePosY()))) {
			moveCamera(1, 0);
			_timer = 0;
		}
		if (input(32) && _timer > 0 &&
			guerrero->checkTeleport(guerrero->getTilePosX(), guerrero->getTilePosY(), x, y)) {
			moveCamera(x, y);
			_timer = -0.5;
		}
	}
	else{
		if (input(32)) {
			moveCamera(27 - tiles[0].getTilePosX(), 22 - tiles[0].getTilePosY());
			guerrero->setAlive(true);
			for (int i = 0; i < enemies.size(); i++) {
				enemies[i].setAlive(true);
			}
		}
	}

	//check if enemies are on screen
	for (int i = 0; i < enemies.size(); i++){
		for (int j = 0; j < tiles.size(); j++){
			if (enemies[i].getAlive() && enemies[i].getTilePosX() == tiles[j].getTilePosX() && enemies[i].getTilePosY() == tiles[j].getTilePosY()) {
				enemies[i].setActive(true);
				enemies[i].setPosX(tiles[j].getPosX());
				enemies[i].setPosY(tiles[j].getPosY());
				break;
			}
			else {
				enemies[i].setActive(false);
			}
		}
		enemies[i].move(deltaTime);
		if (enemies[i].getActive() && guerrero->getAlive()) {
			if (enemies[i].getTilePosX() == guerrero->getTilePosX() && enemies[i].getTilePosY() == guerrero->getTilePosY()) {
				if (!guerrero->getSword()) {
					guerrero->setAlive(false);
				}
				else {
					enemies[i].setAlive(false);
				}
			}
		}
	}
	//check if powerup on screen
	for (int i = 0; i < tiles.size(); i++){
		if (powerUp->getTilePosX() == tiles[i].getTilePosX() && powerUp->getTilePosY() == tiles[i].getTilePosY()) {
			powerUp->setActive(true);
			powerUp->setPosX(tiles[i].getPosX());
			powerUp->setPosY(tiles[i].getPosY());
			break;
		}
		else {
			powerUp->setActive(false);
		}
	}
	if (powerUp->getTilePosX() == guerrero->getTilePosX() && powerUp->getTilePosY() == guerrero->getTilePosY()) {
		powerUp->setActive(false);
		guerrero->setSword(true);
	}
	if (guerrero->getAlive() && guerrero->getTilePosX() == 0 && guerrero->getTilePosY() == 26) {
		gameOver = true;
	}
	//_vel +=  1 * deltaTime;
	//triangle->setRotZ(_vel);
	//square->setRotZ(_vel);
	//Personaje->update(deltaTime);
	Cmanager->CheckLayers();
	return true;
}

void Game::onDraw() {
	if (!gameOver) {
		for (int i = 0; i < tiles.size(); i++) {
			tiles.at(i).Draw();
		}
		if (!guerrero->getSword() && powerUp->getActive()) {
			powerUp->getSprite().Draw();
		}
		if (guerrero->getAlive()) {
			sprite->Draw();
		}
		for (int i = 0; i < enemies.size(); i++) {
			if (enemies[i].getActive()) {
				enemies[i].getSprite().Draw();
			}
		}
	}
	else {
		victoryScreen->Draw();
	}
	//square->Draw();
	//triangle->Draw();
	//colorCube->Draw();
	//circle->Draw();
	//wallSprite->Draw();
}

void Game::moveCamera(int x, int y) {
	for (int i = 0; i < tiles.size(); i++) {
		tiles.at(i).moveTilePos(x, y);
	}
	if (guerrero) {
		guerrero->setTilePosX(guerrero->getTilePosX() + x);
		guerrero->setTilePosY(guerrero->getTilePosY() + y);
	}
}

bool Game::onStop() {
	//delete square;
	//delete triangle;
	//delete circle;
	//delete wallSprite;
	delete sprite;
	//delete colorCube;

	cout << "-OnStop-";
	return true;
}
