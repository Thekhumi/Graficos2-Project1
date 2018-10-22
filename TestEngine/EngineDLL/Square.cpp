#include "Square.h"



Square::Square(Rendering* renderer) :Shape(renderer), _vertex(NULL), _bufferID(-1){
	_vertex = new float[12]{
		-0.5f,-0.5f,0.0f,
		-0.5f,0.0f,0.0f,
		0.5f,-0.5f,0.0f,
		0.5f,0.0f,0.0f,
		
	};
	_shouldDispose = false;
	setVertices(_vertex,4);
}

void Square::setVertices(float* vertex, int vtxcount) {
	if (_shouldDispose) {
		dispose();
	}
	_vertex = vertex;
	_vtxCount = vtxcount;
	_shouldDispose = true;

	_bufferID = _renderer->genBuffer(_vertex, sizeof(float) * vtxcount * 3);
}



void Square::Draw() {

	if (_shouldDispose) {
		_renderer->loadMatrix();
		_renderer->setMatrix(_modelMat);
		if (_material)
		{
			_material->bind();
			_material->setMatrixProperty(_renderer->getMVP());
		}
		_renderer->Draw(_bufferID, _vtxCount, GL_TRIANGLE_STRIP,3);
	}
}

Square::~Square(){
}
