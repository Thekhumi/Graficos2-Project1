#pragma once
#include "Sprite.h"
class SwordPowerup
{
private:
	Sprite * _sprite;
	int _tileposX;
	int _tileposY;
	bool _active = true;
public:
	SwordPowerup(Sprite * sprite, int tileposX, int tileposY);
	Sprite getSprite() { return * _sprite; };
	void setPosX(int x) { _sprite->setPosX(x); };
	void setPosY(int y) { _sprite->setPosY(y); };
	void setTilePosX(int tilePosX) { _tileposX = tilePosX; };
	void setTilePosY(int tilePosY) { _tileposY = tilePosY; };
	void setActive(bool active) { _active = active; };
	bool getActive() { return _active; };
	int getTilePosX() { return _tileposX; };
	int getTilePosY() { return _tileposY; };
	~SwordPowerup();
};

