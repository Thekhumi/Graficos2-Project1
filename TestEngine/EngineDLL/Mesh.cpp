#include "Mesh.h"



Mesh::Mesh(Rendering * renderer) :Shape(renderer){
	_vertex = new float[12]{
		-0.5f,-0.5f,0.0f,
		-0.5f,0.5f,0.0f,
		0.5f,-0.5f,0.0f,
		0.5f,0.5f,0.0f,
	};
	_index = new int[6] {
		0,1,2,2,1,3
	};
	_shouldDispose = false;
	setVertices(_vertex, 4,6);
}

void Mesh::setVertices(float* vertex, int vtxcount, int indexcount) {
	if (_shouldDispose) {
		dispose();
	}
	_vertex = vertex;
	_vtxCount = vtxcount;
	_indexCount = indexcount;
	_shouldDispose = true;

	_bufferID = _renderer->genBuffer(_vertex, sizeof(float) * vtxcount * 3);
	_bufferIDIndex = _renderer->genElementBuffer(_index, sizeof(int) * indexcount);
}

void Mesh::Draw() {

	if (_shouldDispose) {
		_renderer->loadMatrix();
		_renderer->setMatrix(_modelMat);
		if (_material)
		{
			_material->bind();
			_material->setMatrixProperty(_renderer->getMVP());
		}
		_renderer->bind(_bufferID, 3, 0);
		_renderer->bindIndex(_bufferIDIndex);
		_renderer->DrawElements(_indexCount, GL_TRIANGLES);
		_renderer->disableVtx(0);
	}
}
Mesh::~Mesh()
{
}
