#pragma once

#include "Exports.h"
#include "Window.h"
class ENGINEDLL_API Rendering
{
private:
	Window * _window;
	unsigned int _VertexArrayID;
public:
	Rendering();
	~Rendering();
	bool start(Window * window);
	void clearColor(float r,float g,float b,float a);
	void clear();
	void swapBuffer();
	unsigned int  genBuffer(float* vertex, int size);
	void destroyBuffer(unsigned int bufferID);
	void Draw(int bufferID, int size);
	bool stop();
};

