#include "BoxCollider.h"



BoxCollider::BoxCollider(float width, float height, glm::vec3 position, bool isStatic): _width(width),_height(height),_isStatic(isStatic){
	_position = position;
}

void BoxCollider::updatePosition(glm::vec3 position) {
	_position = position;
}

BoxCollider::~BoxCollider()
{
}
