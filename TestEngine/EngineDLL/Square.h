#pragma once
#include "Shape.h"
class ENGINEDLL_API Square :
	public Shape
{

private:
	float*_vertex;
	int _vtxCount;
	unsigned int _bufferID = -1;
public:
	Square(Rendering *renderer);
	void setVertices(float* vertex, int vtxCount);
	void Draw() override;
	~Square();
};

