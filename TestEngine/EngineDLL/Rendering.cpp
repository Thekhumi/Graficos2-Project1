#include "Rendering.h"
#include <iostream>
#include <GLFW\glfw3.h>
using namespace std;


Rendering::Rendering()
{
}

bool Rendering::start(Window* window) {
	cout << "-RendStart-";
	_window = window;
	glfwMakeContextCurrent((GLFWwindow*)_window->getWindow());
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

bool Rendering::stop() {
	cout << "-RendStop-";
	return true;
}


Rendering::~Rendering()
{
}
