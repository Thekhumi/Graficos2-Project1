#include "CompMesh.h"



CompMesh::CompMesh():Component()
{
	setType(CMesh);
	_frustumBox = NULL;
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
	_index = new unsigned int[36]{
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
}

void CompMesh::init(Rendering * rend) {
	_renderer = rend;
	setVertices();
}
void CompMesh::setVertices() {
	if (_shouldDispose) {
		_renderer->destroyBuffer(_bufferID);
		_renderer->destroyBuffer(_bufferIDIndex);
	}
	_shouldDispose = true;

	_bufferID = _renderer->genBuffer(_vertex, sizeof(float) * _vtxCount * 3);
	_bufferIDIndex = _renderer->genElementBuffer(_index, sizeof(unsigned int) * _indexCount);
}

void CompMesh::loadTexture(const char * imagepath, bool hasAlphaC) {
	_texture = TextureImporter::loadBMP(imagepath, hasAlphaC);
	_bufferUV = _renderer->genBuffer(_vertexUV, sizeof(float)* _vertexUVCount * 2);
}

void CompMesh::frustumUpdate(CompFBox * frustumBox) {
	float * xValue = new float[_vtxCount];
	float * yValue = new float[_vtxCount];
	float * zValue = new float[_vtxCount];
	for (int i = 0; i < _vtxCount; i++){
		xValue[i] = _vertex[0 + i * 3];
		yValue[i] = _vertex[1 + i * 3];
		zValue[i] = _vertex[2 + i * 3];
	}
	float minX = xValue[0];
	float minY = yValue[0];
	float minZ = zValue[0];
	float maxX = xValue[0];
	float maxY = yValue[0];
	float maxZ = zValue[0];
	for (int i = 1; i < _vtxCount; i++) {
		//X
		if (minX > xValue[i]) {
			minX = xValue[i];
		}
		if (maxX < xValue[i]) {
			maxX = xValue[i];
		}
		//Y
		if (minY > yValue[i]) {
			minY = yValue[i];
		}
		if (maxY < yValue[i]) {
			maxY = yValue[i];
		}
		//Z
		if (minZ > zValue[i]) {
			minZ = zValue[i];
		}
		if (maxZ < zValue[i]) {
			maxZ = zValue[i];
		}
		frustumBox->updateBox(minX, minY, minZ, maxX, maxY, maxZ);
	}
}
void CompMesh::draw() {
	if (_shouldDispose) {
		if (_material)
		{
			_material->bind();
			_material->setMatrixProperty(_renderer->getMVP());
			if (_texture != NULL)
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

void CompMesh::loadModel(const char * path) {
	//delete originals
	if (_vertex != NULL)
		delete[] _vertex;
	if (_index != NULL)
		delete[] _index;
	if (_vertexUV != NULL)
		delete[] _vertexUV;
	MeshImporter::importModelOld(path, &_vertex, _vtxCount, &_index, _indexCount, &_vertexUV, _vertexUVCount);
	setVertices();
}

void CompMesh::update() {
	if (_frustumBox) {
		frustumUpdate(_frustumBox);
	}
}

CompMesh::~CompMesh()
{
}
