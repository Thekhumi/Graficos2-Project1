#pragma once
#include "exports.h"
#include "Rendering.h"
class ENGINEDLL_API Camera
{
private:
	float eyeX = 0;
	float eyeY = 0;
	float eyeZ = 3;
	float centerX = 0;
	float centerY = 0;
	float centerZ = 0;
	float upX = 0;
	float upY = 1;
	float upZ = 0;
	Rendering * _renderer;

public:
	Camera();
	void setRenderer(Rendering * rend) { _renderer = rend; };
	void walk(float z);
	void strafe(float x);
	void update();
	void cameraInput(bool up, bool down, bool left, bool right, double deltaTime);
	~Camera();
};

