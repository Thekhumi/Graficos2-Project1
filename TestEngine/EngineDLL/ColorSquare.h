#pragma once
#include "Shape.h"
#include "Exports.h"
class ENGINEDLL_API ColorSquare :
	public Shape
{
private:
	float*_vertex;
	int _vtxCount;
	unsigned int _bufferID = -1;

	float* _colorVertex;
	unsigned int _colorBufferId;
	int _colorVertexCant;
public:
	ColorSquare(Rendering* renderer);
	~ColorSquare();
	void setVertices(float* vertex, int vtxCount);
	void setColorVertex(float* vertex, int vertexCant);
	void Draw() override;
};

