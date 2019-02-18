#pragma once
#include "Exports.h"
#include "Sprite.h"
#include "BoxCollider.h"
#include "Animation.h"

class ENGINEDLL_API Avatar
{
private:
	Sprite * _sprite;
	Animation* _anim;
public:
	Avatar(Sprite * sprite, Animation * anim);
	void update(double deltaTime);
	void setSprite(Sprite *sprite) { _sprite = sprite; };
	void setAnimation(Animation *anim) { _anim = anim; };
	Sprite * getSprite() { return _sprite; };
	~Avatar();
};

