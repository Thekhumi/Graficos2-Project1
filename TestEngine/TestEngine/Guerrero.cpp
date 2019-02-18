#include "Guerrero.h"
#include <iostream>

using namespace std;

Guerrero::Guerrero(Sprite * sprite){
	_sprite = sprite;
	blockTiles = { 5,12,31,162,161,182,183,184,185,164,126,127,128,129,131,147,148,149,150,151,152,153,170,149,148,556 };
	//5,12,31,162,161,182,183,184,185,164,126,127,128,129,131,147,148,149,150,151,152,153,170,149,148,556
}

bool Guerrero::move(int dir, int tile) {
	switch (dir) {
	case 0:
		_sprite->setFrame(0);
		break;
	case 1:
		_sprite->setFrame(4);
		break;
	case 2:
		_sprite->setFrame(8);
		break;
	case 3:
		_sprite->setFrame(12);
		break;
	}
	cout << _tilePosX << ",";
	cout << _tilePosY << endl;
	cout << tile << endl;
	for (int i = 0; i < blockTiles.size(); i++){
		if (tile == blockTiles.at(i)) {
			return false;
		}
	}
	return true;
}

void Guerrero::generateTeleportTile(int x, int y, int targetX, int targetY) {
	teleportTile temp;
	temp.tilePosX = x;
	temp.tilePosY = y;
	temp.targetPosX = targetX;
	temp.targetPosY = targetY;
	teleportTiles.push_back(temp);
}

bool Guerrero::checkTeleport(int x, int y, int &newposX, int &newposY) {
	for (int i = 0; i < teleportTiles.size(); i++){
		if (teleportTiles[i].tilePosX == x && teleportTiles[i].tilePosY == y) {
			newposX = teleportTiles[i].targetPosX - x;
			newposY = teleportTiles[i].targetPosY - y;
			return true;
		}
		if (teleportTiles[i].targetPosX == x && teleportTiles[i].targetPosY == y) {
			newposX = teleportTiles[i].tilePosX - x;
			newposY = teleportTiles[i].tilePosY - y;
			return true;
		}

	}
	return false;
}
Guerrero::~Guerrero(){
}
