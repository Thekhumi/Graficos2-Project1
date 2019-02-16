#pragma once
#include "TypeDef.h"
#include "Exports.h"
#include "Rendering.h"
#include "Window.h"
#include "GL\glew.h"
#include "GLFW\glfw3.h"
class ENGINEDLL_API GameBase
{
private:
	Window * _window;
	bool _start;
	bool _stop;
	bool _update;
	int _lastState = false;
protected:
	Rendering * _renderer;
	virtual bool onStart() = 0;
	virtual bool onStop() = 0;
	virtual bool onUpdate(double deltaTime) = 0;
	virtual void onDraw() = 0;
public:
	GameBase();
	bool start();
	bool stop();
	void loop();
	bool input(int key);
	~GameBase();
};

