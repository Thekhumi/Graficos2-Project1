#pragma once
#include "Exports.h"
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

using namespace glm;
class ENGINEDLL_API Plane
{
public:
	glm::vec3 _normal, _point;
	float _d;

	Plane();
	Plane(vec3 &v1, vec3 &v2, vec3 &v3);

	void setPoints(vec3 &v1, vec3 &v2, vec3 &v3);
	static vec3 cross(vec3 &v1, vec3 &v2);
	float distance(vec4 &p);

	void print();
	~Plane();
};

