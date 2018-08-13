#include "Rendering.h"
#include <iostream>
using namespace std;


Rendering::Rendering()
{
}

bool Rendering::start() {
	cout << "RendStart->";
	return true;
}

bool Rendering::stop() {
	cout << "RendStop->";
	return true;
}


Rendering::~Rendering()
{
}
