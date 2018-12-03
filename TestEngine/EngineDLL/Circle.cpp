#include "Circle.h"
#include <math.h>
Circle::Circle(Rendering * renderer, int triangleCant, float radius):Shape(renderer){
	_triangleCant = triangleCant;
	_radius = radius;
	_vtxCount = _triangleCant * 3;
	_degree = 360.0f / _triangleCant;
	_angle = 0.0f;
	_shouldDispose = false;
	_vertex = new float[_vtxCount];
	glm::vec3 _vec;

	for (int i = 0; i < _vtxCount; i += 3) {
		_vec = glm::vec3(cos(_angle), sin(_angle), 0)* _radius;
		_vertex[i] = _vec.x;
		_vertex[i + 1] = _vec.y;
		_vertex[i + 2] = _vec.z;
		_angle += _degree * glm::pi<float>() / 180.0f;
	}
	setVertices(_vertex, _triangleCant);
}

void Circle::setVertices(float* vertex, int vtxcount) {
	if (_shouldDispose) {
		dispose();
	}
	_vertex = vertex;
	_vtxCount = vtxcount;
	_shouldDispose = true;

	_bufferID = _renderer->genBuffer(vertex, sizeof(float) * vtxcount * 3);
}

void Circle::Draw() {
	if (_shouldDispose) {
		_renderer->loadMatrix();
		_renderer->setMatrix(_modelMat);
		if (_material)
		{
			_material->bind();
			_material->setMatrixProperty(_renderer->getMVP());
		}
		_renderer->bind(_bufferID, 3, 0);
		_renderer->Draw(_bufferID, _vtxCount, GL_TRIANGLE_FAN, 3, 0);
		_renderer->disableVtx(0);
	}
}
Circle::~Circle(){
}
