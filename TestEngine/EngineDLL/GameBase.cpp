#include "GameBase.h"
#include <iostream>
using namespace std;

GameBase::GameBase():_renderer(new Rendering()){
}

bool GameBase::start() {
	cout << "GameBaseStart->";
	if (!_renderer->start()) {
		return false;
	}
	return onStart();
}

bool GameBase::stop() {
	onStop();
	_renderer->stop();
	cout << "GameBaseStop->";
	return true;
}

void GameBase::loop() {
	_update = true;
	while (_update) {
		_update = onUpdate();
	}
}


GameBase::~GameBase(){
	if (_renderer) {
		delete _renderer;
	}
}
