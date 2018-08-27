#include <string>
#include "Exports.h"
#pragma once



using namespace std;
class ENGINEDLL_API Window
{
private:
	int _height;
	int _width;
	string _name;
	void* _window;
public:
	Window();
	bool start(int height,int width,const char* name);
	bool stop();
	bool shouldClose();
	bool pollEvents();
	void * getWindow() { return _window; };
	~Window();
};

