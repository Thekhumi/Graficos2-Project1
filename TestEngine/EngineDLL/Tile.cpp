#include "Tile.h"




Tile::Tile(float posX, float posY, Tilemap *tilemap, Rendering * renderer, const char * imagepath, bool hasAlphaC)
	:Sprite(renderer, imagepath, hasAlphaC), _posX(posX), _posY(posY), _tilemap(tilemap) {
	setPosX(posX);
	setPosY(posY);
}

void Tile::setTilePos(float x, float y) {
	setFrame(_tilemap->getTile(x, y));
	_tileposX = x;
	_tileposY = y;
}

void Tile::moveTilePos(float movX, float movY) {
	_tileposX += movX;
	_tileposY += movY;
	setFrame(_tilemap->getTile(_tileposX, _tileposY));
}

Tile::~Tile()
{
}
