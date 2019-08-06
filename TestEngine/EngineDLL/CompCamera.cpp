#include "CompCamera.h"
#include <iostream>

using namespace std;
using namespace glm;

#define ANG2RAD 3.14159265358979323846/180.0
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
		setCamDef();
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

void CompCamera::setCamInternals(float angle, float ratio, float nearD, float farD) {
	_angle = angle;
	_ratio = ratio;
	_nearDist = nearD;
	_farDist = farD;

	_tang = (float)tan(ANG2RAD * angle * 0.5);
	_nearHeight = _nearDist * _tang;
	_nearWidth = _nearHeight * ratio;
	_farHight = _farDist * _tang;
	_farWidth = _farHight * ratio;

	_renderer->setProjectiveMatrixPerspective(_angle, _ratio, _nearDist, _farDist);
	setCamDef();
}
void CompCamera::setCamDef() {
	vec3 dir, nc, fc, x, y, z;
	vec3 pos, target, up;
	pos = { _pos.x, _pos.y, _pos.z };
	target = { _centerPos.x,_centerPos.y,_centerPos.z };
	up = { _up.x, _up.y, _up.z };

	// compute the Z axis of camera
	// this axis points in the opposite direction from
	// the looking direction
	z = pos - target;
	z = normalize(z);

	// X axis of camera with given "up" vector and Z axis
	x = Plane::cross(up, z);
	x = normalize(x);

	// the real "up" vector is the cross product of Z and X
	y = Plane::cross(z, x);

	// compute the centers of the near and far planes
	nc = pos - z * _nearDist;
	fc = pos - z * _farDist;

	// compute the 4 corners of the frustum on the near plane
	ntl = nc + y * _nearHeight - x * _nearWidth;
	ntr = nc + y * _nearHeight + x * _nearWidth;
	nbl = nc - y * _nearHeight - x * _nearWidth;
	nbr = nc - y * _nearHeight + x * _nearWidth;

	// compute the 4 corners of the frustum on the far plane
	ftl = fc + y * _farHight - x * _farWidth;
	ftr = fc + y * _farHight + x * _farWidth;
	fbl = fc - y * _farHight - x * _farWidth;
	fbr = fc - y * _farHight + x * _farWidth;

	// compute the six planes
	// the function set3Points assumes that the points
	// are given in counter clockwise order
	_renderer->pl[TOP].setPoints(ntr, ntl, ftl);
	cout << "TOP: ";
	_renderer->pl[TOP].print();
	_renderer->pl[BOTTOM].setPoints(nbl, nbr, fbr);
	cout << "BOTTOM: ";
	_renderer->pl[BOTTOM].print();
	_renderer->pl[LEFT].setPoints(ntl, nbl, fbl);
	cout << "LEFT: ";
	_renderer->pl[LEFT].print();
	_renderer->pl[RIGHT].setPoints(nbr, ntr, fbr);
	cout << "RIGHT: ";
	_renderer->pl[RIGHT].print();
	_renderer->pl[NEARP].setPoints(ntl, ntr, nbr);
	cout << "NEARP: ";
	_renderer->pl[NEARP].print();
	_renderer->pl[FARP].setPoints(ftr, ftl, fbl);
	cout << "FARP: ";
	_renderer->pl[FARP].print();
}

CompCamera::~CompCamera()
{
}
