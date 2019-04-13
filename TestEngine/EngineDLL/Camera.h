#pragma once
#include "exports.h"
#include "Rendering.h"
class ENGINEDLL_API Camera
{
private:

	//directions
	glm::vec4 _forward = { 0,0,-1,0};
	glm::vec4 _right = {1,0,0,0};
	glm::vec4 _up = { 0,1,0,0 };
	glm::vec4 _pos = { 0, 0, 3, 1 };
	glm::vec4 _centerPos = { 0, 0, 0, 1 };
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
	void cameraInput(bool up, bool down, bool left, bool right,bool w, bool s, bool q, bool e,double deltaTime);
	~Camera();
};

