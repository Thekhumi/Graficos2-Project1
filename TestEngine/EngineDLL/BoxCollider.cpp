#include "BoxCollider.h"



BoxCollider::BoxCollider(float width, float height, glm::vec3 position, bool isStatic, float mass) : _width(width), _height(height), _isStatic(isStatic), _mass(mass) {
	_position = position;
}

void BoxCollider::updatePosition(glm::vec3 position) {
	_position = position;
}

void BoxCollider::setMass(float mass) {
	if (mass <= 0) {
		mass = 0.1f;
	}
	_mass = mass;
	
}

BoxCollider::~BoxCollider()
{
}
