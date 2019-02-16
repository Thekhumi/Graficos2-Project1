#pragma once
#include "Exports.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class ENGINEDLL_API Tilemap
{
private:
	int _tileSize;
	int _height;
	int _width;
	int ** _tiles;
	int _Xtiles;
	int _Ytiles;
public:
	Tilemap(const char * filepath, int tilesize, int height, int width);
	int getTile(int x, int y);
	~Tilemap();
};

