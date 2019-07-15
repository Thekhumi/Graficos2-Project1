#include "Mesh.h"
#include <iostream>
using namespace std;


Mesh::Mesh(Rendering * renderer) :Shape(renderer){
	_index = NULL;
	_vertex = NULL;
	_vertexUV = NULL;
	_texture = NULL;
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
	_index = new unsigned int[36] {
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
	_vtxCount = 8;
	_indexCount = 36;
	
	_shouldDispose = false;
	setVertices();
}

void Mesh::setVertices() {
	if (_shouldDispose) {
		dispose();
		_renderer->destroyBuffer(_bufferIDIndex);
	}
	_shouldDispose = true;

	_bufferID = _renderer->genBuffer(_vertex, sizeof(float) * _vtxCount * 3);
	_bufferIDIndex = _renderer->genElementBuffer(_index, sizeof(unsigned int) * _indexCount);
}

void Mesh::loadTexture(const char * imagepath, bool hasAlphaC) {
	_texture = TextureImporter::loadBMP(imagepath, hasAlphaC);
	_bufferUV = _renderer->genBuffer(_vertexUV, sizeof(float)* _vertexUVCount * 2);
}
void Mesh::Draw() {

	if (_shouldDispose) {
		_renderer->loadMatrix();
		_renderer->setMatrix(_modelMat);
		if (_material)
		{
			_material->bind();
			_material->setMatrixProperty(_renderer->getMVP());
			if(_texture != NULL)
			_material->bindTexture(_texture->getTextureID());
		}
		_renderer->bind(_bufferID, 3, 0);
		if (_texture) {
			_renderer->bind(_bufferUV, 2, 1);
		}
		_renderer->bindIndex(_bufferIDIndex);
		_renderer->DrawElements(_indexCount, GL_TRIANGLES);
		_renderer->disableVtx(0);
		if (_texture != NULL) {
			_renderer->disableVtx(1);
		}
	}
}

void Mesh::loadModel(const char * path) {
	//delete originals
	if (_vertex != NULL)
		delete[] _vertex;
	if (_index != NULL)
		delete[] _index;
	if (_vertexUV != NULL)
		delete[] _vertexUV;
	MeshImporter::importModelOld(path, &_vertex,_vtxCount, &_index, _indexCount,&_vertexUV,_vertexUVCount);
	setVertices();
}
Mesh::~Mesh()
{
}
