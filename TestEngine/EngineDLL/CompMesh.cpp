#include "CompMesh.h"



CompMesh::CompMesh():Component()
{
	setType(CMesh);
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
	_hasFrustrum = false;
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

void CompMesh::FboxSetUp() {
	vec4 vec = { _vertex[0], _vertex[1], _vertex[2], 1};
	_frustrumBox.minX = vec.x;
	_frustrumBox.maxX = vec.x;
	_frustrumBox.minY = vec.y;
	_frustrumBox.maxY = vec.y;
	_frustrumBox.minZ = vec.z;
	_frustrumBox.maxZ = vec.z;
	for (int i = 0; i < _vtxCount; i++){
		int count = i * 3;
		vec = { _vertex[count + 0], _vertex[count + 1], _vertex[count + 2], 1 };
		//min
		if (vec.x < _frustrumBox.minX) {
			_frustrumBox.minX = vec.x;
		}
		if (vec.y < _frustrumBox.minY) {
			_frustrumBox.minY = vec.y;
		}
		if (vec.z < _frustrumBox.minZ) {
			_frustrumBox.minZ = vec.z;
		}
		//max
		if (vec.x > _frustrumBox.maxX) {
			_frustrumBox.maxX = vec.x;
		}
		if (vec.y > _frustrumBox.maxY) {
			_frustrumBox.maxY = vec.y;
		}
		if (vec.z > _frustrumBox.maxZ) {
			_frustrumBox.maxZ = vec.z;
		}
	}
	_hasFrustrum = true;
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


CompMesh::~CompMesh()
{
}
