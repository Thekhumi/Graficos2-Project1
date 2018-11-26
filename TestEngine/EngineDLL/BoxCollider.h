#pragma once
#include "exports.h"
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
class ENGINEDLL_API BoxCollider
{
private:
	glm::vec3 _position;
	float _width;
	float _height;
	bool _isStatic;
	float _mass;
public:
	BoxCollider(float width,float height, glm::vec3 position, bool isStatic, float mass);
	void updatePosition(glm::vec3 position);
	void setWidth(float width) { _width = width; };
	void setHeight(float height) { _height = height; };
	void setMass(float mass);
	float getWidth() { return _width; };
	float getHeight() { return _height; };
	float getMass() { return _mass; };
	glm::vec3 getPos() { return _position; };
	bool getStatic() { return _isStatic; };

	~BoxCollider();
};

