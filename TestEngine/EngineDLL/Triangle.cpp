#include "Triangle.h"



Triangle::Triangle(Rendering* renderer) :Shape(renderer),_vertex(NULL),_bufferID(-1)
{
	
	_vertex = new float[9]{
		-0.5f,0.0f,0.0f,
		0.5f,0.0f,0.0f,
		0.0f,0.5f,0.0f
	};
	_shouldDispose = false;
	setVertices(_vertex, 3);
}

void Triangle::setVertices(float* vertex, int vtxcount) {
	if (_shouldDispose) {
		dispose();
	}
	_vertex = vertex;
	_vtxCount = vtxcount;
	_shouldDispose = true;

	_bufferID = _renderer->genBuffer(_vertex, sizeof(float) * vtxcount * 3);
}

void Triangle::Draw() {
	if (_shouldDispose) {
		_renderer->loadMatrix();
		_renderer->setMatrix(_modelMat);
		if (_material)
		{
			_material->bind();
			_material->setMatrixProperty(_renderer->getMVP());
		}
		_renderer->Draw(_bufferID, _vtxCount, GL_TRIANGLES,3);
	}
}
Triangle::~Triangle(){
}
