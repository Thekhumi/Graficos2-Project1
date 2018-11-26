#include "Entity.h"



Entity::Entity(Rendering * rend){
	_renderer = rend;
	_position[0] = _position[1] = _position[2] = 0.0f;
	_rotation[0] = _rotation[1] = _rotation[2] = 0.0f;
	_scale[0] = _scale[1] = _scale[2] = 1.0f;

	_modelMat = glm::mat4(1.0f);
	_translateMat = glm::mat4(1.0f);
	_rotateXMat = glm::mat4(1.0f);
	_rotateYMat = glm::mat4(1.0f);
	_rotateZMat = glm::mat4(1.0f);
	_scaleMat = glm::mat4(1.0f);

	_collider = NULL;
}


Entity::~Entity()
{
}
