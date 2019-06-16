#pragma once
#include "Shape.h"
#include "Exports.h"
#include "MeshImporter.h"
#include "TextureImporter.h"


class ENGINEDLL_API Mesh :
	public Shape
{
private:
	float*_vertexUV;
	float*_vertex;
	int _vtxCount;
	int _vertexUVCount;
	int _indexCount;
	unsigned int* _index;
	unsigned int _bufferID = -1;
	unsigned int _bufferUV = -1;
	unsigned int _bufferIDIndex = -1;
	Texture *_texture;
public:
	Mesh(Rendering* renderer);
	void setVertices();
	void loadModel(const char * path);
	void loadTexture(const char * imagepath, bool hasAlphaC);
	void Draw() override;
	~Mesh();
};

