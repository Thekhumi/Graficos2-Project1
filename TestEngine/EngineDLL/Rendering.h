#pragma once

#include "Exports.h"
#include "Window.h"
class ENGINEDLL_API Rendering
{
private:
	Window * _window;
public:
	Rendering();
	~Rendering();
	bool start(Window * window);
	void clearColor(float r,float g,float b,float a);
	void clear();
	void swapBuffer();
	bool stop();
};

