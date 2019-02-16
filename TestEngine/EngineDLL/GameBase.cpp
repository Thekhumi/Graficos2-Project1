#include "GameBase.h"
#include <iostream>
using namespace std;

GameBase::GameBase():_renderer(new Rendering()){
}




static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		cout << key << endl;
	}
}

bool GameBase::start() {
	cout << "-GameBaseStart-";
	
	_window = new Window();

	if (!_window->start(640,640,"Cyberpunk2077")) {
		return false;
	}
	glfwSetKeyCallback((GLFWwindow*)_window->getWindow(), key_callback);
	glfwSetInputMode((GLFWwindow*)_window->getWindow(), GLFW_STICKY_KEYS, 1);
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
	double timer = 0;
	double deltaTime = 0;
	double lastTime = 0;
	timer = lastTime = glfwGetTime();
	_update = true;
	_renderer->clearColor(0.45f,0.30f,0.15f,1.0f);
	while (_update && !_window->shouldClose()) {
		timer = glfwGetTime();
		deltaTime = timer - lastTime;
		lastTime = timer;
		_update = onUpdate(deltaTime);
		_window->pollEvents();
		_renderer->clear();
		onDraw();
		_renderer->swapBuffer();
	}
}

bool GameBase::input(int key) {
	int state = glfwGetKey((GLFWwindow*)_window->getWindow(), key);
	if (state == GLFW_PRESS && state != _lastState) {
		return true;
	}
	return false;
}



GameBase::~GameBase(){
	if (_renderer) {
		delete _renderer;
	}
}
