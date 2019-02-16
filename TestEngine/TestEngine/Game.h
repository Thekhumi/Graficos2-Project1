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
class Game : public GameBase
{
private:
	CollisionManager * Cmanager;
	Triangle * triangle;
	Square * square;
	Sprite * sprite;
	Sprite * wallSprite;
	Animation * spriteAnimation;
	Avatar * Personaje;
	ColorSquare * colorCube;
	Circle * circle;
	Tilemap * tilemap;
	vector<Tile> tiles;
	float _vel;
	float _timer = 1;
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

