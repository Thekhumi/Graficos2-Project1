#include "Avatar.h"
#include <iostream>
using namespace std;

Avatar::Avatar(Sprite * sprite, Animation * anim):_sprite(sprite),_anim(anim){
}

void Avatar::update(double deltaTime) {
	_anim->update(deltaTime);
}

Avatar::~Avatar()
{
}
