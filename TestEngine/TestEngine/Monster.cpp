#include "Monster.h"

Monster::Monster(Sprite  * sprite):_sprite(sprite) {
}
void Monster::move(double deltatime) {
	_moveTimer += deltatime;
	if (_moveTimer > 1 && _moveOn) {
		if (!_moved) {
			_tilePosX++;
			_moved = true;
		}
		else {
			_tilePosX--;
			_moved = false;
		}
		_moveTimer = 0;
	}
}
Monster::~Monster() {
}
