#pragma once

#include "Exports.h"
#include "Window.h"
#include "Plane.h"

//include glm

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
class ENGINEDLL_API Rendering{
private:
	Window * _window;
	unsigned int _VertexArrayID;

	glm::mat4 _model;
	glm::mat4 _view;
	glm::mat4 _projection;
	glm::mat4 _mvp;

	glm::mat4 _projectionCacheOrtho;
	glm::mat4 _projectionCachePerspective;

	void updateMVP();
public:
	enum MODE {ORTHO, PERSPECTIVE};
	static enum { OUTSIDE, INTERSECT, INSIDE };
	Plane pl[6];

	bool start(Window * window);
	bool stop();
	void clearColor(float r,float g,float b,float a);
	void clear();
	void swapBuffer();
	unsigned int  genBuffer(float* vertex, int size);
	unsigned int genElementBuffer(unsigned int * index, int size);
	void destroyBuffer(unsigned int bufferID);
	void Draw(int bufferID, int size,int type, int attribSize, int attribType);
	void DrawElements(int size, int type);
	void bind(int bufferID, int attribSize, int attribType);
	void bindIndex(int bufferIDidex);
	void disableVtx(int attribType);
	void loadMatrix();
	void setMatrix(glm::mat4 model);
	void multiplyMatrix(glm::mat4 model);
	static  unsigned int genTexture(unsigned int width, unsigned int height, unsigned char * data, bool hasAlpha);
	glm::mat4& getMVP() {
		return _mvp;
	}
	glm::mat4 getModel() {
		return _model;
	}
	Window getWindow() {
		return * _window;
	}
	void setViewMatrix(glm::vec3 pos, glm::vec3 center, glm::vec3 up);
	void setProjectionMatrixOrtho(float left, float right, float bottom, float top, float zNear, float zFar);
	void setProjectiveMatrixPerspective(float fovy, float aspect, float zNear, float zFar);
	void setProjectionMode(MODE mode);

	//frustrum
	bool pointInFrustrum(vec4 &p);
	Rendering();
	~Rendering();
};

