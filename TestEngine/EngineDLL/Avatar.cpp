#include "Avatar.h"
#include <iostream>
using namespace std;

Avatar::Avatar(Sprite * sprite, Animation * anim):_sprite(sprite),_anim(anim){
}

void Avatar::walk(float speed) {
	_sprite->setPosX(_sprite->getPosX() + speed);
}

void Avatar::update(double deltaTime) {
	walk(3 * deltaTime);
	_anim->update(deltaTime);
}

Avatar::~Avatar()
{
}
