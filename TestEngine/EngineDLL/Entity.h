#pragma once
#include "Rendering.h"
#include "Material.h"
#include <gl\glew.h>
class ENGINEDLL_API Entity
{
protected:
	Rendering * _renderer;
	Material * _material;
	bool _shouldDispose;

	glm::vec3 _position;
	glm::vec3 _rotation;
	glm::vec3 _scale;

	glm::mat4 _modelMat;
	
	glm::mat4 _translateMat;
	glm::mat4 _rotateXMat;
	glm::mat4 _rotateYMat;
	glm::mat4 _rotateZMat;
	glm::mat4 _scaleMat;

	void updateModelMatrix() {
		_modelMat = _translateMat * _rotateXMat * _rotateYMat * _rotateZMat * _scaleMat;
	}

public:
	void setScale(float x,float y,float z) {
		_scale[0] = x;
		_scale[1] = y;
		_scale[2] = z;

		_scaleMat = glm::scale(glm::mat4(1.0f), _scale);
		updateModelMatrix();
	}
	
	void setPos(float x, float y, float z) {
		_position[0] = x;
		_position[1] = y;
		_position[2] = z;

		_translateMat = glm::translate(glm::mat4(1.0f), _position);
		updateModelMatrix();
	}

	void setRotX(float x) {
		_rotation[0] = x;
		glm::vec3 axis;
		axis[2] = axis[1] = 0.0f;
		axis[0] = 1.0f;

		_rotateXMat = glm::rotate(glm::mat4(1.0f), x, axis);
		updateModelMatrix();
	}

	void setRotY(float y) {
		_rotation[0] = y;
		glm::vec3 axis;
		axis[2] = axis[0] = 0.0f;
		axis[1] = 1.0f;

		_rotateYMat = glm::rotate(glm::mat4(1.0f), y, axis);
		updateModelMatrix();
	}

	void setRotZ(float z) {
		_rotation[0] = z;
		glm::vec3 axis;
		axis[0] = axis[1] = 0.0f;
		axis[2] = 1.0f;

		_rotateZMat = glm::rotate(glm::mat4(1.0f), z, axis);
		updateModelMatrix();
	}

	glm::vec3 getRotation() {
		return _rotation;
	}
	Entity(Rendering * rend);
	virtual void Draw() = 0;
	~Entity();
};

