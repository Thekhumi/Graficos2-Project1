#include "CompCamera.h"
#include <iostream>

using namespace std;


CompCamera::CompCamera() :Component()
{
	setType(CCamera);
}

void CompCamera::walk(float z) {
	_pos += z * _forward;
	_centerPos += z * _forward;
	update();
}

void CompCamera::pitch(float rotX) {

	glm::mat4 rot = glm::rotate(glm::mat4(1.0f), rotX, glm::vec3(_right.x, _right.y, _right.z));

	_forward = rot * _forward;
	_up = rot * _up;

	_centerPos = _pos + _forward;

	update();
}

void CompCamera::yaw(float rotY) {
	glm::mat4 rot = glm::rotate(glm::mat4(1.0f), rotY, glm::vec3(_up.x, _up.y, _up.z));

	_forward = rot * _forward;
	_right = rot * _right;

	_centerPos = _pos + _forward;

	update();
}

void CompCamera::roll(float rotZ) {
	glm::mat4 rot = glm::rotate(glm::mat4(1.0f), rotZ, glm::vec3(_forward.x, _forward.y, _forward.z));

	_up = rot * _up;
	_right = rot * _right;

	_centerPos = _pos + _forward;

	update();
}
void CompCamera::update() {

	if (_renderer) {
		_renderer->setViewMatrix((glm::vec3)_pos, (glm::vec3)_centerPos, (glm::vec3)_up);
	}
}

void CompCamera::strafe(float x) {
	_pos += x * _right;
	_centerPos += x * _right;
	update();
}

void CompCamera::cameraInput(bool up, bool down, bool left, bool right, bool w, bool s, bool q, bool e, bool lShift, bool rShift, double deltatime) {
	if (up) {
		walk(1 * deltatime);
	}
	if (down) {
		walk(-1 * deltatime);
	}
	if (left) {
		strafe(-1 * deltatime);
	}
	if (right) {
		strafe(1 * deltatime);
	}
	if (w) {
		pitch(1 * deltatime);
	}
	if (s) {
		pitch(-1 * deltatime);
	}
	if (q) {
		yaw(1 * deltatime);
	}
	if (e) {
		yaw(-1 * deltatime);
	}
	if (lShift) {
		roll(-1 * deltatime);
	}
	if (rShift) {
		roll(1 * deltatime);
	}
	//if()
	//cout << eyeX <<" "<<eyeY << " "<<eyeZ << endl;
	//cout << centerX << " " << centerY << " " << centerZ << endl;
}

CompCamera::~CompCamera()
{
}
