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
	return true;
}

void Rendering::clearColor(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
}

void Rendering::clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}
void Rendering::swapBuffer() {
	glfwSwapBuffers((GLFWwindow*)_window->getWindow());
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
void Rendering::destroyBuffer(unsigned int bufferID) {
	glDeleteBuffers(1,&bufferID);
}
bool Rendering::stop() {
	cout << "-RendStop-";
	return true;
}
void Rendering::Draw(int bufferID, int size) {
	// 1st attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, size); // Starting from vertex 0; 3 vertices total -> 1 triangle
	glDisableVertexAttribArray(0);
}

Rendering::~Rendering()
{
}
