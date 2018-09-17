#include "Window.h"
#include <iostream>
#include <GLFW\glfw3.h>

using namespace std;
Window::Window():_width(1),_height(1),_name("EnginePepito"){
}

bool Window::start(int height,int width, const char* name) {
	cout << "-WindowStart-";
	_height = height;
	_width = width;
	_name = name;
	if (!glfwInit()) {
		cout << "Failed to initialize GLFW";
		return false;
	}
	
	_window = glfwCreateWindow(_width, _height, name, NULL, NULL);
	if (!_window) {
		glfwTerminate();
		return false;
	}
	return true;
}

bool Window::stop() {
	cout << "-WindowStop-";
	if (_window) {
		glfwDestroyWindow((GLFWwindow*)_window);
	}
	return true;
}

bool Window::pollEvents() {
	glfwPollEvents();
	return true;
}
bool Window::shouldClose() {
	return glfwWindowShouldClose((GLFWwindow*)_window);
}
Window::~Window()
{
}
