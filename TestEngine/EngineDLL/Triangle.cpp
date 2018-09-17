#include "Triangle.h"



Triangle::Triangle(Rendering* renderer) :Entity(renderer),_vertex(NULL),_bufferID(-1)
{
	_vertex = new float[9]{
	 -1.0f,-1.0f,0.0f,
	 1.0f,-1.0f,0.0f,
	 0.0f,1.0f,0.0f
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
void Triangle::dispose() {
	_renderer->destroyBuffer(_bufferID);
}

void Triangle::setMaterial(Material * mat) {
	_material = mat;
}

void Triangle::Draw() {

	if (_material)
	{
		_material->bind();
	}
	_renderer->Draw(_bufferID, _vtxCount);
}
Triangle::~Triangle()
{
	dispose();
}
