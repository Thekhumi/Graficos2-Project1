#pragma once

#include "Exports.h"
#include "Window.h"

//include glm

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
class ENGINEDLL_API Rendering
{
private:
	Window * _window;
	unsigned int _VertexArrayID;

	glm::mat4 _model;
	glm::mat4 _view;
	glm::mat4 _projection;
	glm::mat4 _mvp;

	void updateMVP();
public:

	bool start(Window * window);
	bool stop();
	void clearColor(float r,float g,float b,float a);
	void clear();
	void swapBuffer();
	unsigned int  genBuffer(float* vertex, int size);
	void destroyBuffer(unsigned int bufferID);
	void Draw(int bufferID, int size,int type, int attribSize, int attribType);
	void bind(int bufferID, int attribSize, int attribType);
	void disableVtx(int attribType);
	void loadMatrix();
	void setMatrix(glm::mat4 model);
	void multiplyMatrix(glm::mat4 model);
	static  unsigned int genTexture(unsigned int width, unsigned int height, unsigned char * data, bool hasAlpha);
	glm::mat4& getMVP() {
		return _mvp;
	}
	Window getWindow() {
		return * _window;
	}

	Rendering();
	~Rendering();
};

