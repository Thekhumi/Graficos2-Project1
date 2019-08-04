#pragma once
#include "Component.h"
#include "exports.h"
#include "Rendering.h"
#include "Plane.h"
using namespace glm;

class ENGINEDLL_API CompCamera : public Component
{
private:
	enum{
		TOP = 0, BOTTOM, LEFT,
		RIGHT, NEARP, FARP
	};


	//directions
	vec4 _forward = { 0,0,-1,0 };
	vec4 _right = { 1,0,0,0 };
	vec4 _up = { 0,1,0,0 };
	vec4 _pos = { 0, 0, 3, 1 };
	vec4 _centerPos = { 0, 0, 0, 1 };

	//rendering
	Rendering * _renderer;

public:
	vec3 ntl, ntr, nbl, nbr, ftl, ftr, fbl, fbr;
	float _nearDist, _farDist, _ratio, _angle, _tang;
	float _nearWidth, _nearHeight, _farWidth, _farHight;

	CompCamera();
	void setRenderer(Rendering * rend) { _renderer = rend; };
	void yaw(float yRot);
	void pitch(float xRot);
	void roll(float zRot);
	void walk(float z);
	void strafe(float x);
	void update() override;
	void cameraInput(bool up, bool down, bool left, bool right, bool w, bool s, bool q, bool e, bool lShift, bool rShift, double deltaTime);
	~CompCamera();

	//Frustum
	void setCamInternals(float angle, float ratio, float nearD, float farD);
	void setCamDef();
};

