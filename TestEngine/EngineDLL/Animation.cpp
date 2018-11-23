#include "Animation.h"


Animation::Animation(Sprite * sprite)
{
	_sprite = sprite;
	_play = true;
	_cont = _firstFrame = _lastFrame = _timer = 0;
	_frames = NULL;
}

void Animation::setAnimation(int*frames, int framesCant, double speed) {
	_frames = frames;
	_framesCant = framesCant;
	_cont = 0;
	_firstFrame = _frames[0];
	_lastFrame = _frames[framesCant];
	_speed = speed;
}

void Animation::update(double deltaTime) {
	if (_play && _sprite != NULL && _frames != NULL) {
		_timer += deltaTime;
		if (_timer >= 1/_speed) {
			_timer = 0;
			if (_cont == _framesCant) {
				_cont = 0;
			}
			_sprite->setFrame(_frames[_cont]);
			_cont++;
		}
	}
}

Animation::~Animation()
{
}
