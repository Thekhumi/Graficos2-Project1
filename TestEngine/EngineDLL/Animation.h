#pragma once
#include "Exports.h"
#include "Sprite.h"
class ENGINEDLL_API Animation
{
private:
	bool _play = true;
protected:
	Sprite * _sprite;
	double _speed;
	double _timer;
	int _firstFrame;
	int _lastFrame;
	int _framesCant;
	int _cont;
	int* _frames;
public:
	Animation(Sprite * sprite);
	void setAnimation(int * frames, int frameCant, double speed);
	void update(double deltaTime);
	void setPlay(bool play) { _play = play; };
	~Animation();
};

