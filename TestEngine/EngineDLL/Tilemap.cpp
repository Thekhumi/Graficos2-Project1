#include "Tilemap.h"
#include <fstream>
#include <iostream>

using namespace std;


Tilemap::Tilemap(const char * filepath, int tilesize, int height, int width)
:_tileSize(tilesize),_height(height) ,_width(width){
	_Xtiles = _width / tilesize;
	_Ytiles = _height / tilesize;
	_tiles = new  int*[_Ytiles];
	for (int i = 0; i < _Ytiles; i++){
		_tiles[i] = new int[_Xtiles];
	}
	fstream archivoMapa;
	archivoMapa.open(filepath, ios::in);
	char letra;
	char temp[200];
	int num = 0;
	int x = 0;
	int y = 0;
	bool full = false;
	archivoMapa.getline(temp, 200);
	archivoMapa.read((char*)&letra, sizeof(letra));
	cout << endl;
	while (!archivoMapa.eof() && !full) {
		if (isdigit(letra)) {
			num *= 10;
			num += letra - 48;
			cout << letra;
		}
		else if (letra == '-') {
			cout << "-";
			num *= -1;
		}
		if (letra == ',') {
			_tiles[y][x] = num;
			cout << ",";
			num = 0;
			x++;
		}
		else if (letra == '\n') {
			_tiles[y][x] = num;
			num = 0;
			cout << endl;
			x = 0;
			if (y == _Ytiles -1) {
				full = true;
			}
			else {
				y++;
			}

		}
		archivoMapa.read((char*)&letra, sizeof(letra));
	}
	archivoMapa.close();
}

int Tilemap::getTile(int x, int y) {
	if ( x > 0 && x < _Xtiles && y < _Ytiles && y > 0) {
		return _tiles[y][x];
	}
	else return 5;
}


Tilemap::~Tilemap()
{
}
