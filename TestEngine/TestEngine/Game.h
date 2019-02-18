#pragma once
#include "GameBase.h"
#include "Triangle.h"
#include "Square.h"
#include "Sprite.h"
#include "Defs.h"
#include "TextureImporter.h"
#include "Animation.h"
#include "Avatar.h"
#include "CollisionManager.h"
#include "ColorSquare.h"
#include "Circle.h"
#include "Tilemap.h"
#include "Tile.h"
#include <vector>
//GAME
#include "Guerrero.h"
#include "Monster.h"
#include "SwordPowerup.h"
class Game : public GameBase
{
private:
	CollisionManager * Cmanager;
	Triangle * triangle;
	Square * square;
	Sprite * sprite;
	Sprite * wallSprite;
	Sprite * victoryScreen;
	Animation * spriteAnimation;
	Avatar * Personaje;
	ColorSquare * colorCube;
	Circle * circle;
	Tilemap * tilemap;
	vector<Monster> enemies;
	vector<Tile> tiles;
	SwordPowerup * powerUp;
	float _vel;
	float _timer = 1;
	int x = 0;
	int y = 0;
	int enemyCount = 5;
	bool gameOver = false;

	Guerrero * guerrero;
protected:
	bool onStart() override;
	bool onStop() override;
	bool onUpdate(double _deltaTime) override;
	void onDraw() override;
public:
	Game();
	void moveCamera(int x,int y);
	~Game();
};

