#pragma once
#include "Shape.h"
#include "Exports.h"
#include "MeshImporter.h"

struct vertexData {
	float x;
	float y;
	float z;
	float UV;
};
class ENGINEDLL_API Mesh :
	public Shape
{
private:
	float*_vertex;
	int _vtxCount;
	int _indexCount;
	int* _index;
	unsigned int _bufferID = -1;
	unsigned int _bufferIDIndex = -1;
public:
	Mesh(Rendering* renderer);
	void setVertices(float* vertex, int vtxCount, int indexcount);
	void loadModel(const char * path);
	void Draw() override;
	~Mesh();
};

