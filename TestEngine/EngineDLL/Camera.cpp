#include "Camera.h"



Camera::Camera(){
}

void Camera::walk(float z) {
	eyeZ += z;
	centerZ += z;
	update();
}
void Camera::update() {
	float vecEye[3] = { eyeX,eyeY,eyeZ };
	float vecCenter[3] = { centerX,centerY,centerZ };
	float vecUp[3] = { upX,upY,upZ };
	if (_renderer) {
		_renderer->setViewMatrix(vecEye, vecCenter, vecUp);
	}
}

void Camera::strafe(float x) {
	eyeX += x;
	centerX += x;
	update();
}

void Camera::cameraInput(bool up, bool down, bool left, bool right,double deltatime){
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
}
Camera::~Camera(){
}
