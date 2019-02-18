#pragma once
#include "Sprite.h"
#include <vector>
struct teleportTile{
	int tilePosX;
	int tilePosY;
	int targetPosX;
	int targetPosY;
};
class Guerrero
{
private:
	Sprite * _sprite;
	int _tilePosX;
	int _tilePosY;
	vector<int> blockTiles;
	vector<teleportTile> teleportTiles;
	bool _alive = true;
	bool _sword = false;
public:
	Guerrero(Sprite * sprite);
	bool move(int dir,int tile);

	void setSprite(Sprite sprite) { *_sprite = sprite; };
	Sprite getSprite() { return *_sprite; };
	void setAlive(bool alive) { _alive = alive; };
	bool getAlive() { return _alive; };
	bool getSword() { return _sword; };
	void setTilePos(int tilePosX, int tilePosY) { _tilePosX = tilePosX; _tilePosY = tilePosY; };
	void setTilePosX(int tilePosX) { _tilePosX = tilePosX; };
	void setTilePosY(int tilePosY) { _tilePosY = tilePosY; };
	void setSword(bool sword) { _sword = sword; };
	int getTilePosX() { return _tilePosX; };
	int getTilePosY() { return _tilePosY; };
	void generateTeleportTile(int x, int y, int targetX, int targetY);
	bool checkTeleport(int x, int y, int &newPosX, int &newPosY);
	~Guerrero();
};

