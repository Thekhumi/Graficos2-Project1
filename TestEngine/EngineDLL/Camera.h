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

	//directions
	glm::vec3 forward = { 0,0,-1};
	glm::vec3 right = {1,0,0};
	glm::vec3 up = { 0,1,0 };
	Rendering * _renderer;

public:
	Camera();
	void setRenderer(Rendering * rend) { _renderer = rend; };
	void yaw(float yRot);
	void pitch(float xRot);
	void roll(float zRot);
	void walk(float z);
	void strafe(float x);
	void update();
	void cameraInput(bool up, bool down, bool left, bool right,bool q, bool e,double deltaTime);
	~Camera();
};

