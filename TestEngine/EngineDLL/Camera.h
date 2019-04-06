#pragma once
#include "exports.h"
class ENGINEDLL_API Camera
{
private:

public:
	Camera();
	void walk(float z);
	void strafe(float x);
	void update();
	~Camera();
};

