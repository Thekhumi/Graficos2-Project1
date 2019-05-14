#include "Mesh.h"
#include <iostream>
using namespace std;


Mesh::Mesh(Rendering * renderer) :Shape(renderer){
	_vertex = new float[24]{
		// front
	-1.0, -1.0,  1.0,
	 1.0, -1.0,  1.0,
	 1.0,  1.0,  1.0,
	-1.0,  1.0,  1.0,
	// back
	-1.0, -1.0, -1.0,
	 1.0, -1.0, -1.0,
	 1.0,  1.0, -1.0,
	-1.0,  1.0, -1.0
	};
	_index = new int[36] {
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3
	};
	_shouldDispose = false;
	setVertices(_vertex, 8,36);
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

void Mesh::loadModel(const char * path) {
	MeshImporter::importModel(path, _vertex, _index);
}
Mesh::~Mesh()
{
}
