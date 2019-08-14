#include "Rendering.h"
#include <iostream>
#include <gl\glew.h>
#include <GLFW\glfw3.h>

using namespace std;


Rendering::Rendering()
{
}

bool Rendering::start(Window* window) {
	cout << "-RendStart-";
	_window = window;
	glfwMakeContextCurrent((GLFWwindow*)_window->getWindow());

	if (glewInit() != GLEW_OK) {
		return false;
	}

	glGenVertexArrays(1, &_VertexArrayID);
	glBindVertexArray(_VertexArrayID);

	_view = glm::lookAt(
		glm::vec3(0, 0, 3),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0))
		;
	_model = glm::mat4(1);
	updateMVP();

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	return true;
}

void Rendering::clearColor(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
}

void Rendering::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Rendering::swapBuffer() {
	glfwSwapBuffers((GLFWwindow*)_window->getWindow());
}

unsigned int Rendering::genTexture(unsigned int width, unsigned int height, unsigned  char * data,bool hasAlpha) {
	unsigned int textureID;
	glGenTextures(1, &textureID);
	// Se "Ata" la nueva textura : Todas las futuras funciones de texturas van a modificar esta textura
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Se le pasa la imagen a OpenGL
	if (hasAlpha) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, data);
	}
	else {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	return textureID;
}

unsigned int Rendering::genBuffer(float* vertex, int size) {
	// This will identify our vertex buffer
	unsigned int vertexbuffer;
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, size,vertex , GL_STATIC_DRAW);
	return vertexbuffer;
}

unsigned int Rendering::genElementBuffer(unsigned int * index, int size) {
	// This will identify our vertex buffer
	unsigned int vertexbuffer;
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, index, GL_STATIC_DRAW);
	return vertexbuffer;
}
void Rendering::destroyBuffer(unsigned int bufferID) {
	glDeleteBuffers(1,&bufferID);
}
bool Rendering::stop() {
	cout << "-RendStop-";
	return true;
}
void Rendering::Draw(int bufferID, int size, int type,int attribSize,int attribType) {
	glDrawArrays(type, 0, size); // Starting from vertex 0; 3 vertices total -> 1 triangle
}
void Rendering::DrawElements(int size, int type) {
	glDrawElements(type,      // mode
		size,    // count
		GL_UNSIGNED_INT,   // type
		(void*)0 // element array buffer offset);
	);
}

void Rendering::bind(int bufferID,int attribSize,int attribType) {
	glEnableVertexAttribArray(attribType);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glVertexAttribPointer(
		attribType,        
		attribSize,         // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
}

void Rendering::bindIndex(int bufferIDindex) {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferIDindex);
}

void Rendering::disableVtx(int attribType) {
	glDisableVertexAttribArray(attribType);
}

void Rendering::updateMVP() {
	_mvp = _projection * _view * _model;
}

void Rendering::loadMatrix() {
	_model = glm::mat4(1.0f);
	updateMVP();
}
void Rendering::setMatrix(glm::mat4 model) {
	_model = model;
	updateMVP();
}
void Rendering::multiplyMatrix(glm::mat4 model) {
	_model *= model;
	updateMVP();
}

void Rendering::setViewMatrix(glm::vec3 pos, glm::vec3 center, glm::vec3 up) {
	_view = glm::lookAt(
		pos,
		center,
		up)
		;
	updateMVP();
}

void Rendering::setProjectionMatrixOrtho(float left, float right, float bottom, float top, float zNear, float zFar) {
	_projectionCacheOrtho = glm::ortho(left, right, bottom, top, zNear, zFar);
}

void Rendering::setProjectiveMatrixPerspective(float fovy, float aspect, float zNear, float zFar) {
	_projectionCachePerspective = glm::perspective(fovy, aspect, zNear, zFar);
}

void Rendering::setProjectionMode(MODE mode) {
	switch (mode) {
	case ORTHO:
		_projection = _projectionCacheOrtho;
		break;
	case  PERSPECTIVE:
		_projection = _projectionCachePerspective;
		break;
	}
	updateMVP();
}

Rendering::~Rendering()
{
}
