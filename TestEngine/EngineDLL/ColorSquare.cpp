#include "ColorSquare.h"



ColorSquare::ColorSquare(Rendering * renderer):Shape(renderer), _vertex(NULL), _bufferID(-1) {
	_vertex = new float[12]{
		-0.5f,-0.5f,0.0f,
		-0.5f,0.0f,0.0f,
		0.5f,-0.5f,0.0f,
		0.5f,0.0f,0.0f,

	};
	_colorVertex = new float[12]{
		0.249f,  0.281f,  0.542f,
		0.382f,  0.656f,  0.429f,
		0.474f,  0.134f,  0.572f,
		0.112f,  0.567f,  0.890f
	};
	_shouldDispose = false;
	setVertices(_vertex, 4);
	setColorVertex(_colorVertex, 4);
}

void ColorSquare::setVertices(float* vertex, int vtxcount) {
	if (_shouldDispose) {
		dispose();
	}
	_vertex = vertex;
	_vtxCount = vtxcount;
	_shouldDispose = true;

	_bufferID = _renderer->genBuffer(_vertex, sizeof(float) * vtxcount * 3);
}

void ColorSquare::Draw() {
	if (_shouldDispose) {
		_renderer->loadMatrix();
		_renderer->setMatrix(_modelMat);
		if (_material)
		{
			_material->bind();
			_material->setMatrixProperty(_renderer->getMVP());
		}
		_renderer->bind(_bufferID,3, 0);
		_renderer->bind(_colorBufferId, 3, 1);
		_renderer->Draw(_bufferID, _vtxCount, GL_TRIANGLE_STRIP, 3, 0);
		_renderer->disableVtx(0);
		_renderer->disableVtx(1);
	}
}
void ColorSquare::setColorVertex(float* vertex, int vertexCant) {
	_colorVertex = vertex;
	_shouldDispose = true;
	_colorVertexCant = vertexCant;
	_colorBufferId = _renderer->genBuffer(_colorVertex, sizeof(float)* vertexCant * 3);
}
ColorSquare::~ColorSquare()
{
}
