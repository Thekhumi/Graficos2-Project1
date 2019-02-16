#pragma once
#include "Sprite.h"
#include "Exports.h"
#include "Tilemap.h"
class ENGINEDLL_API Tile :
	public Sprite
{
private:
	int _posX;
	int _posY;
	int _tileposX;
	int _tileposY;
	Tilemap * _tilemap;
public:
	Tile(float posX, float posY,Tilemap * tilemap,Rendering * renderer, const char * imagepath, bool hasAlphaC);
	void setTilePos(float x, float y);
	void moveTilePos(float movX, float movY);
	~Tile();
};

