#include "GameBase.h"
#include <iostream>
using namespace std;

GameBase::GameBase():_renderer(new Rendering()){
}

bool GameBase::start() {
	cout << "-GameBaseStart-";
	
	_window = new Window();

	if (!_window->start(640,480,"Cyberpunk2077")) {
		return false;
	}
	
	_renderer = new Rendering();

	if (!_renderer->start(_window)) {
		return false;
	}
	return onStart();
}

bool GameBase::stop() {
	onStop();
	_window->stop();
	_renderer->stop();
	cout << "-GameBaseStop-";
	return true;
}

void GameBase::loop() {
	_update = true;
	_renderer->clearColor(0.0f,1.0f,0.5f,0.4f);
	while (_update && !_window->shouldClose()) {
		_update = onUpdate();
		_window->pollEvents();
		_renderer->clear();
		onDraw();
		_renderer->swapBuffer();
	}
}


GameBase::~GameBase(){
	if (_renderer) {
		delete _renderer;
	}
}
