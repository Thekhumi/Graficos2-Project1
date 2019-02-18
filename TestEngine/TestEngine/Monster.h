#pragma once
#include "Sprite.h"
class Monster
{
private:
	Sprite * _sprite;
	int _tilePosX;
	int _tilePosY;
	double _moveTimer = 0;
	bool _active = false;
	bool _moved = false;
	bool _moveOn = false;
	bool _alive = true;
public:
	Monster(Sprite * sprite);
	void move(double deltatime);
	void setMove(bool moveOn) { _moveOn = moveOn; };

	Sprite getSprite() { return *_sprite; };
	void setPosX(int x) { _sprite->setPosX(x); };
	void setPosY(int y) { _sprite->setPosY(y); };
	void setActive(bool active) { _active = active; };
	void setTilePos(int tilePosX, int tilePosY) { _tilePosX = tilePosX; _tilePosY = tilePosY; };
	void setTilePosX(int tilePosX) { _tilePosX = tilePosX; };
	void setTilePosY(int tilePosY) { _tilePosY = tilePosY; };
	bool getActive() { return _active; };
	void setAlive(bool alive) { _alive = alive; };
	bool getAlive() { return _alive; };
	int getTilePosX() { return _tilePosX; };
	int getTilePosY() { return _tilePosY; };
	~Monster();
};
