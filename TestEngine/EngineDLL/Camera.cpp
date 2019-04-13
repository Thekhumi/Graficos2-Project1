#include "Camera.h"
#include <iostream>

using namespace std;


Camera::Camera(){
}

void Camera::walk(float z) {
	_pos.z += z;
	_centerPos.z += z;
	update();
}

void Camera::pitch(float rotX) {

	glm::mat4 rot = glm::rotate(glm::mat4(1.0f), rotX, glm::vec3(1.0f, 0, 0));

	_forward = rot * _forward;
	_up = rot * _up;

	_centerPos = _pos + _forward;
	
	update();
}

void Camera::yaw(float rotY) {
	glm::mat4 rot = glm::rotate(glm::mat4(1.0f), rotY, glm::vec3(0.0f, 1.0f, 0));

	_forward = rot * _forward;
	_right = rot * _right;

	_centerPos = _pos + _forward;

	update();
}
void Camera::update() {

	if (_renderer) {
		_renderer->setViewMatrix((glm::vec3)_pos, (glm::vec3)_centerPos, (glm::vec3)_up);
	}
}

void Camera::strafe(float x) {
	_pos.x += x;
	_centerPos.x += x;
	update();
}

void Camera::cameraInput(bool up, bool down, bool left, bool right,bool w, bool s,bool q, bool e,double deltatime){
	if (up) {
		walk(-1 * deltatime);
	}
	if (down) {
		walk(1 * deltatime);
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
	//cout << eyeX <<" "<<eyeY << " "<<eyeZ << endl;
	//cout << centerX << " " << centerY << " " << centerZ << endl;
}
Camera::~Camera(){
}
